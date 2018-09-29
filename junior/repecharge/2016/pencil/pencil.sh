#!/bin/bash
i=1
while [ $i -le 20 ]
do
	echo pencil$i
	cp -f pencil$i.in pencil.in
	./pencil
	if diff pencil$i.ans pencil.out ; then
		echo Ac
	fi
	i=$(($i+1))
done
