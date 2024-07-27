n=$#
echo "Total arguments passed: $n"

arr=$@
echo $arr

arr2=$*
echo $arr2

echo "Traversing using for loop"
for i in $arr; do
  echo $i
done