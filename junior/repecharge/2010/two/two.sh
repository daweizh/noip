#!/bin/bash
i=1
while [ $i -le 10 ]
do
	echo two$i
	cp -f two$i.in two.in
	./two
	if diff two$i.ans two.out ; then
		echo Ac
	fi
	i=$(($i+1))
done
