
factorial(){
  n=$1
  facto=1
  for ((i=2 ; i <= n; i++)); do
    facto=$((facto * i))
  done
  echo $facto
}

read -r -p "Enter a number: " num


# -r option: This option tells the read command to treat backslashes literally, preventing them from being interpreted as escape characters.
# This will ensure that any backslashes present in the input are read correctly, preventing potential issues caused by incorrect interpretation


temp=$num
sum=0

while [ "$temp" -gt 0 ]
do
  rem=$((temp % 10))
  k=$(factorial $rem)
  sum=$((sum + k))
  temp=$((temp / 10))
done

if ((sum == num)); then
  echo "$num is Krishnamurty number"
else
  echo "$num is NOT Krishnamurty number"
fi