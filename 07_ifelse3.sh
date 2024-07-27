#second largest number

read -p "Enter first number: " a
read -p "Enter second number: " b
read -p "Enter third number: " c

if [ $a -gt $b ] && [ $a -lt $c ]
then
  echo "$a is the second largest"
elif [ $b -gt $a ] && [ $b -lt $c ]
then
  echo "$b is the second largest"
else
  echo "$c is the second largest"
fi
