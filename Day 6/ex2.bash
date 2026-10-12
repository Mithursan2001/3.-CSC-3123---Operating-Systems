echo "Enter the number between 1-9"
read n

if [ $n -ge 1 ]&&[ $n -le 9 ]
then
	square=$(($n*$n))
	echo "square=$square"
	
else
echo "Enter the correct number:"
fi