fileName="StudenRec1.txt"

if [ ! -f $fileName ]; then
  echo "No file $fileName exist"
  exit 1

fi

echo "Current content of file: "
cat $fileName
echo

read -p "Enter the number of new records: " n

for ((i=1; i<=n; i++)); do
  read -p "Enter name: " name
  read -p "Enter roll: " roll
  read -p "Enter marks: " marks
  echo "$name $roll $marks" >> $fileName
done

sort -k3 -n $fileName -o $fileName


echo "sorted data: "
cat $fileName
echo