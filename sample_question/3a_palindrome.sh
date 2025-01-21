
palindrome(){
  local num=$1
  local rev=0
  local temp=$num
  while [ $temp -gt 0 ]; do
    rem=$((temp % 10))
    rev=$((rev * 10 + rem))
    temp=$((temp / 10))
  done
  if  [ $num -eq $rev ]; then
    echo 1
  else
    echo 0
  fi
}

if [ $# -eq 0 ]; then
  echo "No arguments passed"
else
  for num in "$@"; do
    if [ $(palindrome $num) -eq 1 ]; then
      echo $num
    fi
  done
fi

