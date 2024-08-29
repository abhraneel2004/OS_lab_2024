factorial(){
  n=$1
  fact=1
  for ((i=2; i<=n; i++)); do
    fact=$((fact*i))
  done
  echo $fact
}

ncr(){
  local n=$1
  local r=$2
  local t1=$(factorial $n)
  #echo "$n! = $t1"
  local t2=$(factorial $r)
  #echo "$r! = $t2"
  local t3=$(factorial $((n-r)))
  #echo "$((n-r))!= $t3"
  t4=$(( t3*t2 ))
  t1=$((t1/t4))
  echo $t1
}

#echo $(ncr 5 4)

read -p "Enter no. of rows: " rows

for (( i=0 ; i<rows; i++ )); do
  #space printing
  for ((j=0; j<$((rows-i)); j++)); do
    echo -n " "
  done
  for ((j=0; j<=i; j++)); do
    k=$(ncr $i $j)
    echo -n "$k "
  done
  echo ""
done

