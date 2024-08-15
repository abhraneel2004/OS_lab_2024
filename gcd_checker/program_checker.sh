`ls ./GCD_programs > temp2.txt` # create a temporary file
num_lines=$(wc -l < temp2.txt)

for ((i=1; i <= num_lines; i++)) do
	filename=`head -n $i temp2.txt|tail -n 1`
	# test.txt contains the test cases
	l=$(wc -l < test.txt) # no of test cases
	p=0
	for (( j=1 ; j <= $l; j++)) do
		x=`head -n $j test.txt|tail -n 1|cut -d " " -f 1`
		y=`head -n $j test.txt|tail -n 1|cut -d " " -f 2`
		z=`head -n $j test.txt|tail -n 1|cut -d " " -f 3`
		out=$(sh ./GCD_programs/$filename $x $y)
	
		if [ $out == $z ]; then
			p=$((p + 1))
			
		else
			continue
		fi
	done
	if [[ $p -eq $l ]]; then
		echo "$filename All Test cases passed"
		echo "------------------"
		echo " "
	else
		echo "$filename $p/$l Test case(s) passed"
		echo "------------------"
		echo " "
	fi
	
done
`rm temp2.txt` # delete that temporary file