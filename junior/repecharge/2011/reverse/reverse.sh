#!/bin/bash
i=1
while [ $i -le 10 ]
do
	echo reverse$i
	cp -f reverse$i.in reverse.in
	./reverse
	if diff reverse$i.ans reverse.out ; then
		echo Ac
	fi
	i=$(($i+1))
done
