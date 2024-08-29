read -p "Enter number of rows: " n

for ((i=1; i<=n; i++)); do
  #space printing
  for ((j=1; j<=$((n-i)); j++)); do
    echo -n " "
  done
  for ((j=1; j<$((2 * i)); j++)); do
    echo -n "*"
  done
  echo ""
done