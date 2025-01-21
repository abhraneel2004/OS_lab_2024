numbers=("$@")
size=${#numbers[@]}

for (( i=0; i<size; i++ )); do
  echo "${numbers[i]}"
done
echo
echo "---------------------"
echo
for i in "${numbers[@]}"; do
  echo "$i"
done