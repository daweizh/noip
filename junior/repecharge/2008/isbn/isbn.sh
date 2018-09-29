#!/bin/bash
i=1
while [ $i -le 10 ]
do
	echo isbn$i
	cp -f isbn$i.in isbn.in
	./isbn
	if diff isbn$i.ans isbn.out ; then
		echo Ac
	fi
	i=$(($i+1))
done
