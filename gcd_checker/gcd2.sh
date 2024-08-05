#!/bin/bash

gcdfunc() {
  a=$1
  b=$2

  # Check if inputs are valid numbers
  if ! [[ $a =~ ^[0-9]+$ ]]; then
    echo "Not_Possible"
    return
  elif ! [[ $b =~ ^[0-9]+$ ]]; then
    echo "Not_Possible"
    return
  elif [ $b -eq 0 ]; then
    echo "Not_Possible"
    return
  elif [ $a -eq 0 ]; then
    echo 0
    return
  fi

  # Use the Euclidean algorithm to compute the GCD
  while [ $b -ne 0 ]; do
    temp=$b
    b=$((a % b))
    a=$temp
  done

  echo $a
}

gcdfunc $1 $2
