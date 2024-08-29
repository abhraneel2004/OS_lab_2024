read -p "Enter number of rows: " n

for ((i=1; i<=n; i++)); do
  for ((j=n; j>=i; j--)); do
    echo -n "*"
  done
  echo ""
done
