function factorial(){
echo "Enter the number: "
read n

fact=1
if [ $n -lt 0 ]
then
	echo "Error"
else
	for (( i=1; i<=n; i++ ))
	do
	fact=$(($fact*$i))
	done
	echo "factorial=$fact"
fi
}
factorial
