fileName="StudenRec1.txt"

if [ ! -f $fileName ]; then
  echo "File $fileName does not exist"
  exit 1
fi


echo "Current content of file: "
cat $fileName
echo

read -p "Enter the roll number to update: " roll
read -p "Enter the new marks: " marks

if grep -q " $roll " $fileName; then
  sed -i "s/^\(.* $roll \)[0-9]*/\1$marks/" $fileName
  echo "Marks updated"
else
  echo "Roll number not found"
fi
echo
echo "Updated content of file: "
cat $fileName
echo