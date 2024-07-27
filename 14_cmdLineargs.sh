pname=$0
echo "Process Name= $pname"

num=$1
echo "first argument= $num"

num2=$2
echo "second argument= $num2"

#using for loop
for ((i=1; i <= $num2; i+=2)); do
  echo "$i"

done