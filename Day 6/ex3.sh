echo "Enter the 5 marks"
read mark1
read mark2
read mark3
read mark4
read mark5

sum1=$(($mark1+$mark2+$mark3+$mark4+$mark5))
echo "sum=$sum1"

average1=$((($mark1+$mark2+$mark3+$mark4+$mark5)/5))
echo "average=$average1"

if [ $sum1 -gt 400 ]&&[ $sum1 -le 500 ]
then
echo "very good"
	else
	if [ $sum1 -gt 300 ]&&[ $sum1 -le 400 ]
	then
	echo "good"
		else
		if [ $sum1 -gt 200 ]&&[ $sum1 -le 300 ]
		then
		echo "poor"
			else
			echo "very bad"
		fi
	fi
fi
