#!/bin/bash
[ -f p$1.cpp ] && CCMD="g++ -o p$1.outprg p$1.cpp -lm"
[ -f p$1.c ] && CCMD="gcc -o p$1.outprg p$1.c -lm"
echo "[33mCompiling......[31m"
if $CCMD
then
    echo "[32mCompile Succeed."
else
    echo "Compile Failed.[0m"
    exit
fi
echo "[0m"
chmod +x p$1.outprg
TOTTIME=0
#MEMLIMIT=$(curl http://172.0.11.5/OnlineJudge/problem_show.php?id=$1 2>/dev/null |\
#    grep '内存限制' |\
#    awk '{print $3}' |\
#    awk -F '：' '{print $2}' |\
#    awk -F 'K' '{print $1}')
for i in \
    $(curl http://172.0.11.5/OnlineJudge/Data/$1/config.ini 2>/dev/null | sed '1d')
do
    INPUTFILE=$(echo $i | awk -F '|' '{print $1}')
    OUTFILE=$(echo $i | awk -F '|' '{print $2}')
    TIMELIMIT=$(echo $i | awk -F '|' '{print $3}')
    echo "====[33mDownloading Data[0m====="
    curl http://172.0.11.5/OnlineJudge/Data/$1/$INPUTFILE > data.in
    curl http://172.0.11.5/OnlineJudge/Data/$1/$OUTFILE >data.out
    echo =========================
    rm mydata.out 2> /dev/null
    ./ujudger-run $(echo $TIMELIMIT|awk '{print (int($1)==$1?$1:int(int($1*10/10+1)))*2}') ./p$1.outprg data.in mydata.out > res
    EXITSTAT=$(cat res | awk '{print $6}')
    USEDTIME=$(cat res | awk '{print $3}')
    USEDMEM=$(cat res | awk '{print $4}')
    echo Tested $INPUTFILE
    if [ $EXITSTAT -eq 11 ]
    then
            ANSRES="[31mRuntime Error[0m"
            echo $ANSRES
    else
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
        echo
    fi
    echo =========================
    echo Used time:$USEDTIME s
    echo Used memory:$USEDMEM KB
    echo Time limit:$TIMELIMIT s
#    echo Memory limit:$MEMLIMIT KB
    echo =========================
    fi
    if [ $(echo $USEDTIME $TIMELIMIT | awk '{if($1>$2){print "1"}else {print "0"}}') = 1 ]
    then
        TIMERES="[31mTime Limit Exceed."
    else
        TIMERES=$(printf "[32mTime:%11f" $USEDTIME)
    fi
    [ $EXITSTAT -eq 0 ] || TIMERES=""
    MEMRES=$(printf "[33mMemory:%11dKB" $USEDMEM)
    echo "$INPUTFILE	$ANSRES	$TIMERES   $MEMRES[0m" >> result
done
cat result
echo
rm result
rm data.in
rm data.out
rm mydata.out
rm res
rm p$1.outprg
