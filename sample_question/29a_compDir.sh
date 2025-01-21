path1="./Directory/"
path2="./Directory2/"

if [ ! -d $path1 ]; then
  echo "No directory $path1 exist"
  exit 1
fi

if [ ! -d $path2 ]; then
  echo "No directory $path2 exist"
  exit 1
fi

f1=0
f2=0

for item in "$path1"/* ; do
  if [ -f $item ]; then
    ((f1++))
  fi
done

for item in "$path2"/* ; do
  if [ -f $item ]; then
    ((f2++))
  fi
done

if [ $f1 -gt $f2 ]; then
  echo "$path1 has more files"
else
  echo "$path2 has more files"
fi