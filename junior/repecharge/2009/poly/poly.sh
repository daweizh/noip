#!/bin/bash
i=1
while [ $i -le 10 ]
do
	echo poly$i
	cp -f poly$i.in poly.in
	./poly
	if diff poly$i.ans poly.out ; then
		echo Ac
	fi
	i=$(($i+1))
done
