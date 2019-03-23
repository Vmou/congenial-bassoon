#!/bin/bash

iter=$1;
RANGE=$2;

i=$iter;
while [ $i -gt 0 ]; do
    number=${RANDOM};
    let "number %= ${RANGE}";
    echo $number;
    i=`expr $i - 1`;
done
