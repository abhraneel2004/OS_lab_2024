
read -p "Enter the number of terms: " n
result=""
term1=0
term2=1
for((i=0; i<=n; i++)); do
  if [ $i -eq 0 ]; then
    result="$result $term1"
  elif [ $i -eq 1 ]; then
    result="$result $term2"
  else
    term3=$((term1 + term2))
    result="$result $term3"
    term1=$term2
    term2=$term3
  fi
done
echo $result > temp.txt