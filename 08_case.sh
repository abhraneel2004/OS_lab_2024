read -r -p "Enter the marks: " marks

case $marks in 

4[0-9]) echo "Grade is D" ;;
5[0-9]) echo "Grade is C" ;;
6[0-9]) echo "Grade is B" ;;
7[0-9]) echo "Grade is A" ;;
8[0-9]) echo "Grade is E" ;;
9[0-9]|100) echo "Grade is O" ;;
*) echo "Failed";
esac