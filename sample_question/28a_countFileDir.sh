dirpath="./Directory"

if [ ! -d $dirpath ]; then
  echo "No directory $dirpath exist"
  exit 1
fi

dirCnt=0
fileCnt=0

for item in "$dirpath"/* ; do
  if [ -d $item ]; then
    echo "Directory: $(basename $item)"
    ((dirCnt++))
  elif [ -f $item ]; then
    echo "File: $(basename $item)"
    ((fileCnt++))
  fi
done

echo "$dirpath:"
echo "Total files: $fileCnt"
echo "Total directories: $dirCnt"