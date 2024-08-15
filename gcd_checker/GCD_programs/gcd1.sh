gcdfunc(){
  a=$1
  b=$2
  
  if [[ $a =~ ^[a-zA-Z]+$ ]]; then
    echo "Not_Possible"
  elif [[ $b =~ ^[a-zA-Z]+$ ]]; then
    echo "Not_Possible"
  elif [ $b -eq 0 ]; then
    echo "Not_Possible"
  elif [[ $a -eq 0 ]]; then
    echo 0
  else
    res=1
    if [ $a -gt $b ]; then
      min=$b
    else
      min=$a
    fi
    for ((i=1; i<=min; i++)); do
      if [ $((a%i)) -eq 0 ] && [ $((b%i)) -eq 0 ]; then
        res=$i
      fi
    done
    echo $res
  fi
}

gcdfunc $1 $2