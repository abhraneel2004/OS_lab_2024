read -p "Enter date : " dob

IFS="/"
set $dob

dd=$1
mm=$2
yyyy=$3

echo "Your Dob::"
echo "Year: $yyyy"
echo "Month: $mm"
echo "Day: $dd"

#system date
d2=$(date +%d)
m2=$(date +%m)
y2=$(date +%Y)

echo "Current Date::"
echo "Year: $y2"
echo "Month: $m2"
echo "Day: $d2"

yr=`expr $y2 - $yyyy`
mo=`expr $m2 - $mm`
if [[ $mo -lt 0 ]]; thenif [[ $if [[ $(leapYear $yyyy) -eq 1 ]] && [[ $mm -eq 2 ]] && [[ $dd -le 29 ]]; then
    echo "Valid Date"(leapYear $yyyy) -eq 1 ]] && [[ $mm -eq 2 ]] && [[ $dd -le 29 ]]; then
    echo "Valid Date"
  yr=$((yr - 1))
  mo=$((mo + 12))if [[ $(leapYear $yyyy) -eq 1 ]] && [[ $mm -eq 2 ]] && [[ $dd -le 29 ]]; then
    echo "Valid Date"
fi
da=`expr $d2 - $dd`
if [[ $da -lt 0 ]]; then
  mo=$((mo - 1))
  da=$((da + 30))
fi

echo "Age::"
echo "Year: $yr"
echo "Month: $mo"
echo "Day: $da"



