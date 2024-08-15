gcdfunc(){
  a=$1
  b=$2

  if [[ $a =~ ^[a-zA-Z]+$ ]]; then
    echo 2
  elif [[ $b =~ ^[a-zA-Z]+$ ]]; then
    echo "Not_Possible"
  elif [ $b -eq 0 ]; then
    echo "Not_Possible"	
  elif [[ $a -eq 0 ]]; then
    echo 0
  else
    while [ $b -ne 0 ]; do
      temp=$b
      b=$((a%b))
      a=$temp
    done
    echo $a
  fi
}

gcdfunc $1 $2