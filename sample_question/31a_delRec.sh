fileName="StudenRec1.txt"

if [ ! -f $fileName ]; then
  echo "No file $fileName exist"
  exit 1
fi

echo "Current content of file: "
cat $fileName
echo

read -p "Enter the roll number to delete: " roll

if grep -q " $roll " $fileName; then
  sed -i "/ $roll /d" $fileName
  echo "Record deleted"
else
  echo "No record with roll $roll found"
fi

echo "Updated content of file: "
cat $fileName
echo