echo "Enter number a float: "
read a
echo "Enter number b float: "
read b
c=`expr "echo scale=2, $a + $b" | bc`
echo "Sum is $c"