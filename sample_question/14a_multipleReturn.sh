Y(){
  x=$1
  n=$2
  if [ $n -eq 1 ]; then
    val=$((x * x))
    val=$((val + 1))
    echo $val
  elif [ $n -eq 2 ]; then
    val=$(echo "scale=2; $x / $n" | bc)
    val=$(echo "scale=2; $val + 1" | bc)
    echo $val
  elif [ $n -eq 3 ]; then
    val=$((2 * x))
    val=$((val + 1))
    echo $val
  else
    echo $((1 + n * x))
  fi
}

read -p "Enter x: " x
read -p "Enter n: " n
echo "Y($x, $n) = $(Y $x $n)"