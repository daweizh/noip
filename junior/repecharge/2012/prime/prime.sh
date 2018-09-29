#!/bin/bash
i=1
while [ $i -le 10 ]
do
	echo prime$i
	cp -f prime$i.in prime.in
	./prime
	if diff prime$i.ans prime.out ; then
		echo Ac
	fi
	i=$(($i+1))
done
