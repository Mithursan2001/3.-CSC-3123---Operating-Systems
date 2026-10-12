echo "Enter the number: "
read n

function square(){
	square=$(($n*$n))
	echo "square=$square"
}
function volume(){
	volume=$(($n*$n*$n))
	echo "volume=$volume"
}
square
volume