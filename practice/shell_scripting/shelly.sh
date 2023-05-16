#!/bin/sh

x=10
y='yeet'
read z

echo $x
echo $y
echo "How dare you enter $z"

a=5
b=6
c=4

(( x=$a+$b ))
echo "The value of x is $x"

if [[ $a -gt $b && $a -gt $c ]]; then
	echo "a is greater"
elif [[ $b -gt $a && $b -gt $c ]]; then
	echo "b is greater"
else
	echo "c is greater"
fi

while [[ $a -gt 0 ]];
do
	echo "While loop iteration $a"
	(( $a-- ))
done



