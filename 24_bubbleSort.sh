read -p "Enter the array size: " n
echo "Enter the array elements: "
for ((i=0; i<n; i++)); do
  read arr[i]
done
echo -n "Array before sorting: "
echo ${arr[@]}

for ((i=0; i<n; i++)); do
  for ((j=0; j<n-i-1; j++)); do
    if [[ ${arr[j]} -gt ${arr[j+1]} ]]; then
      temp=${arr[j]}
      arr[j]=${arr[j+1]}
      arr[j+1]=$temp
    fi
  done
done

echo -n "Array after sorting: "
echo ${arr[@]}
