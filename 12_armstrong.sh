countdig(){
  n=$1
  c=0
  while [ $n -gt 0 ]
  do
    ((c++))
    n=$((n / 10))
  done
  echo $c
}

pow() {
  base=$1
  exp=$2

  result=1
  for ((i=1; i<=exp; i++)); do
    result=$((result * base))
  done
  echo $result
}

num=$1
echo "Number of digits in $num is $(countdig $num)"

dig=$(countdig $num)
temp=$num
sum=0
while [ $temp -gt 0 ]; do
  rem=$((temp % 10))
  k=$(pow rem dig)
  sum=$((sum + k))
  temp=$((temp / 10))
done

if ((sum == num)); then
  echo "$num is an Armstrong number"
else
  echo "$num is NOT an Armstrong number"
fi