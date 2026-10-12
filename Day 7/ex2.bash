echo "Enter your birth date: "
read num

x=$(($num%9))
if [ $x -eq 0 ]
then
	x=9
fi

echo "Birth number is : $x"
echo -n "You are "
case $x in
1) echo "Lucky";;
2) echo "Rich";;
3) echo "Talanted";;
4) echo "Strength";;
5) echo "Neutral";;
6) echo "Grazy";;
7) echo "Helpful";;
8) echo "Double";;
9) echo "Perfection";;
*) echo "wrong number";;
esac

