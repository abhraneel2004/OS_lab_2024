pow(){
  local base=$1
  local exp=$2
  local result=1
  for((i=1; i<=exp; i++)); do
    result=$(echo "scale=6; $result * $base" | bc)
  done
  echo $result
}

read -p "Enter the value of x: " x
read -p "Enter the value of n: " n

sum=1
mul=-1
for((i=2; i<=n; i++)); do
  term=$(echo "scale=6; $x / $i" | bc)
  power=$(pow $term $i)
  term2=$(echo "scale=6; $mul * $power" | bc)
  sum=$(echo "scale=6; $sum + $term2" | bc)
  mul=$((mul * -1))
done
echo "Sum of the series is" $sum
