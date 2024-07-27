factorial() {
  n=$1
  facto=1
  for ((i=1; i<=n; i++)); do
    facto=$((facto * i))
  done
  echo $facto
}

power() {
  base=$1
  exp=$2

  result=1
  for ((i=1; i<=exp; i++)); do
    result=$((result * base))
  done
  echo $result
}

x=$1
n=$2

sum=0

for ((i=0; i < n; i++)); do
  k1=$((2 * i))
  k2=$(power $x $k1)
  k3=$(factorial $k1)
  k4=$(echo "scale=3; $k2 / $k3" | bc)
  sum=$(echo "scale=3; $sum + $k4" | bc)
done

echo "sum = $sum"
