echo "Enter number a float: "
read a
echo "Enter number b float: "
read b
c=$(echo "scale=3; $a + $b" | bc)
echo "Sum is $c"