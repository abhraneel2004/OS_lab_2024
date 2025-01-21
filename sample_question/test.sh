fileN="Test1.txt"

if [ ! -f $fileN ]; then
  echo "File $fileN does not exist"
  exit 1
fi

lines=$(wc -l < $fileN)

for((i=1; i<=lines; i++)); do
  name=`head -n $i $fileN| tail -n 1| cut -d "|" -f 1`
  roll=`head -n $i $fileN| tail -n 1| cut -d "|" -f 2`
  marks=`head -n $i $fileN| tail -n 1| cut -d "|" -f 3`
  echo "$name $roll $marks"
done