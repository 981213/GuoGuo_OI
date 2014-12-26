#!/bin/bash 
echo "[33mCompiling......[31m"
if g++ -o p$1.outprg p$1.cpp -lm
then
    echo "[32mCompile Succeed."
else
    echo "Compile Failed.[0m"
    exit
fi
echo "[0m"
chmod +x p$1.outprg
TOTTIME=0
MEMLIMIT=$(curl http://172.0.11.5/OnlineJudge/problem_show.php?id=$1 2>/dev/null |\
    grep '内存限制' |\
    awk '{print $3}' |\
    awk -F '：' '{print $2}' |\
    awk -F 'K' '{print $1}')
for i in \
    $(curl http://172.0.11.5/OnlineJudge/Data/$1/config.ini 2>/dev/null | sed '1d')
do
    INPUTFILE=$(echo $i | awk -F '|' '{print $1}')
    OUTFILE=$(echo $i | awk -F '|' '{print $2}')
    TIMELIMIT=$(echo $i | awk -F '|' '{print $3}')
    curl http://172.0.11.5/OnlineJudge/Data/$1/$INPUTFILE > data.in 2>/dev/null
    curl http://172.0.11.5/OnlineJudge/Data/$1/$OUTFILE >data.out 2>/dev/null
    echo =========================
    /usr/bin/time -f "%U %M" -o used_time ./p$1.outprg < data.in >mydata.out
    USEDTIME=$(cat used_time | awk '{print $1}')
    USEDMEM=$(cat used_time | awk '{print $2}')
    echo Tested $INPUTFILE
    if diff -uNZ data.out mydata.out > /dev/null
    then
        echo Answer Correct.
        ANSRES="[32mAnswer Correct.  "
    else
        echo Answer Inorrect.
        ANSRES="[31mAnswer Inorrect."
        echo Your answer:
        cat mydata.out
        echo
        echo Correct answer:
        cat data.out
    fi
    echo =========================
    echo Used time:$USEDTIME s
    echo Used memory:$USEDMEM KB
    echo Time limit:$TIMELIMIT s
    echo Memory limit:$MEMLIMIT KB
    echo =========================
    if [ $(echo $USEDTIME $TIMELIMIT | awk '{if($1>$2){print "1"}else {print "0"}}') = 1 ]
    then
        TIMERES="[31mTime Limit Exceed."
    else
        TIMERES="[32mTime Check Passed."
    fi
    if [ $USEDMEM -ge $MEMLIMIT ]
    then
        MEMRES="[31mMemory Limit Exceed."
    else
        MEMRES="[32mMemory Check Passed."
    fi
    echo "$INPUTFILE	$ANSRES	$TIMERES	$MEMRES[0m" >> result
done
cat result
echo
rm result
rm data.in
rm data.out
rm mydata.out
rm used_time
rm p$1.outprg
