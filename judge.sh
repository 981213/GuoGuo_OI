#!/bin/bash 
g++ -o p$1 p$1.cpp -lm
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
    echo
    echo =========================
    /usr/bin/time -f "Used time:%U s \nUsed memory:%M KB" -o used_time ./p$1 < data.in >mydata.out
    echo Tested $INPUTFILE
    echo Your answer:
    cat mydata.out
    echo
    echo Correct answer:
    cat data.out
    if diff -uNZ data.out mydata.out > /dev/null
    then
        echo Answer Correct.
    else
        echo Answer Inorrect.
    fi
    echo =========================
    cat used_time
    echo Time limit:$TIMELIMIT s
    echo Memory limit:$MEMLIMIT KB
    echo =========================
done
rm data.in
rm data.out
rm mydata.out
rm used_time
