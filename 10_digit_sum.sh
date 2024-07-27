read -p "Enter a number: " num
temp=$num
sum=0
while [ $temp -gt 0 ]
do
  rem=$((temp % 10))
  sum=$((sum + rem))
  temp=$((temp / 10))
done
echo "Sum of digits of $num is $sum"