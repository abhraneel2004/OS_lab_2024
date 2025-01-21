leapYear(){
  year=$1
  if [ $((year % 4)) -eq 0 ]; then
    if [ $((year % 100)) -eq 0 ] && [ $((year % 400)) -ne 0 ]; then
      echo 0
    else
      echo 1
    fi
  else
    echo 0
  fi
}

read -p "Enter date (DD/MM/YYYY):" date1

IFS="/" read -r dd mm yyyy <<< "$date1"

if [ $yyyy -lt 1 ]; then
  echo "Invalid year."
  exit 1
fi

if [ $mm -eq 1 -o $mm -eq 3 -o $mm -eq 5 -o $mm -eq 7 -o $mm -eq 8 -o $mm -eq 10 -o $mm -eq 12 ] && [ $dd -gt 31 -o $dd -lt 1 ]; then
  echo "Invalid Date"
elif [ $mm -eq 2 ] && [ $(leapYear $yyyy) -eq 1 ] && [ $dd -gt 29 -o $dd -lt 1 ]; then
  echo "Invalid Date"
elif [ $mm -eq 2 ] && [ $(leapYear $yyyy) -eq 0 ] && [ $dd -gt 28 -o $dd -lt 1 ]; then
  echo "Invalid Date"
elif [ $mm -eq 4 -o $mm -eq 6 -o $mm -eq 9 -o $mm -eq 11 ] && [ $dd -gt 31 -o $dd -lt 1 ]; then
  echo "Invalid Date"
elif [ $mm -gt 12 -o $mm -lt 1 ]; then
  echo "Invalid Date"
else
  echo "Valid Date"
fi
  