read -p "Enter a number: " num

facto=1
if ((num < 0)); then
  echo "Factorial of negative number does not exist"
else
  for ((i=1; i<=num; i++)); do
    facto=$((facto*i))
  done
  echo "Factorial of $num is $facto"
fi