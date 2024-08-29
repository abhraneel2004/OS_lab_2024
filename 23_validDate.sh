leapYear(){
  yr=$1
  if [[ $((yr % 4)) -eq 0 ]]; then
    if [[ $((yr % 100)) -eq 0 ]] && [[ $((yr % 400)) -ne 0 ]]; then
      echo 0
    else
      echo 1
    fi
  else 
    echo 0
  fi
}

read -p "Enter date : " date1

IFS="/"
set $date1

dd=$1
mm=$2
yyyy=$3

echo "Input:: $date1"
if [[ $yyyy -gt 0 ]] && [[ $mm -gt 0 ]] && [[ $mm -le 12 ]] && [[ $dd -gt 0 ]] && [[ $dd -le 31 ]]; then
  arr=(31 28 31 30 31 30 31 31 30 31 30 31)
  if [[ $(leapYear $yyyy) -eq 1 ]] && [[ $mm -eq 2 ]] && [[ $dd -le 29 ]]; then
    echo "Valid Date"if [[if [[ $(leapYear $yyyy) -eq 1 ]] && [[ $mm -eq 2 ]] && [[ $dd -le 29 ]]; then
    echo "Valid Date"if [[ $(leapYear $yyyy) -eq 1 ]] && [[ $mm -eq 2 ]] && [[ $dd -le 29 ]]; then
    echo "Valid Date"if [[ $(leapYear $yyyy) -eq 1 ]] && [[ $mm -eq 2 ]] && [[ $dd -le 29 ]]; then
    echo "Valid Date" $(leapYear $yyyy) -eq 1 ]] && [[ $mm -eq 2 ]] && [[ $dd -le 29 ]]; then
    echo "Valid Date"
  elif [[ $dd -le ${arr[`expr $mm - 1`]} ]]; then
    echo "Valid Date"
  else
    echo "Invalid Date" 
  fi
else
  echo "Invalid Date"
fi