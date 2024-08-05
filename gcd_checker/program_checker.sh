lineOuter=$(wc -l < temp.txt) #no. of files in directory
# echo $lineOuter
for ((i=1;i <= $lineOuter;i++)) do
  filename=`head -n $i temp.txt |tail -n 1` #extracting file name
  if [[ $filename == *.sh ]]; then #check if the file is a shell script
    lineInner=$(wc -l < test.txt)
    pc=0
    for ((j=1;j <= $lineInner;j++)) do
      x=$(head -n $j test.txt|tail -n 1|cut -d " " -f 1) #getting first value
      y=$(head -n $j test.txt|tail -n 1|cut -d " " -f 2) #getting second value
      z=$(head -n $j test.txt|tail -n 1|cut -d " " -f 3) #getting third value
      out=$(sh $filename $x $y) # fetching the output of the program
      if [ $((out == z)) ]; then
        echo "Test case $j Passed ✓"
        pc=$((pc+1))
      else
        echo "Test case $j Failed ***"
        break # if one test case fails, break the loop
      fi
    done
    if [[ $pc -eq $lineInner ]]; then
      echo "$filename is valid program"
      echo " "
      echo "------------------------"
      echo " "
    else
      echo "$pc / $lineInner Test Cases Passed"
      echo " "
      echo "------------------------"
      echo " "
    fi
  fi
done