size=5

for ((i=0; i<size; i++)); do
  read -r arr[i]
done

# print array
echo ${arr[@]}