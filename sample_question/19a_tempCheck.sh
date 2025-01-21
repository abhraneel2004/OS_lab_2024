fileName="inputTemp.txt"

if [ ! -f $fileName ]; then
  echo "File not exist"
fi

store="outputTemp.txt"

lines=$(wc -l < $fileName)
for((i=1; i<=lines; i++)); do
  day=`head -n $i $fileName| tail -n 1| cut -d " " -f 1`
  x=`head -n $i $fileName| tail -n 1| cut -d " " -f 2`
  if [ $x -lt 15 ]; then
    res="$day VeryCold"
  elif [ $x -ge 15 -a $x -lt 25 ]; then
    res="$day Cold"
  elif [ $x -ge 25 -a $x -lt 35 ]; then
    res="$day Hot"
  elif [$x -gt 35 ]; then
    res="$day VeryHot"
  fi
  echo $res >> $store
done
