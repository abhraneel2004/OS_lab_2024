fileName="temp2.txt"

if [ ! -f $fileName ]; then
  echo "No file $fileName exist"
  exit 1
fi

lines=$(wc -l < $fileName)
echo "number of lines in $fileName = $lines"

for ((i = 1; i<=lines; i++)); do
  x=`head -n $i $fileName| tail -n 1`
  a[i]=$x
  # check palindrome
done

echo ${a[@]}

file2="temp.txt"
IFS=' ' read -r -a b < $file2
echo ${b[@]}