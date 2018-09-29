#!/bin/bash
i=1
while [ $i -le 10 ]
do
	echo coin$i
	cp -f coin$i.in coin.in
	./coin
	if diff coin$i.ans coin.out ; then
		echo Ac
	fi
	i=$(($i+1))
done
