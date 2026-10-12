fact(){
	echo "Enter the number: "
	read n

	if [ $n -lt 0 ]
	then
		echo "Enter positive integer: "
	else if [ $n -eq 0 ]
	then
	echo "factorial =1"
	else
		fact=1
		while [ $n -gt 0 ]
		do 
			fact=$((fact*$n))
			n=$(($n-1))
		done
		echo "factorial=$fact"
		fi
	fi
}
fact