#!/bin/bash
i=1
while [ $i -le 10 ]
do
	echo count$i
	cp -f count$i.in count.in
	./count
	if diff count$i.ans count.out ; then
		echo Ac
	fi
	i=$(($i+1))
done
