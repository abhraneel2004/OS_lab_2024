filesName="temp.txt"
IFS=' ' read -r -a b < "$filesName"
max=${b[0]}
min=${b[0]}
for i in "${b[@]}" ; do
  if [ "$i" -gt "$max" ]; then
    max=$i
  fi
  if [ "$i" -lt "$min" ]; then
    min=$i
  fi
done

echo "Max: $max"
echo "Min: $min"