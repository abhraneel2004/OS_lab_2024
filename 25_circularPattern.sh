clear
read -p "Enter the radius: " r
for ((i=0; i<360; i=i+10)); do
  th1=$(echo "scale=4; 3.14/180*$i" | bc | awk '{print cos($1)}')
  th2=$(echo "scale=4; 3.14/180*$i" | bc | awk '{print sin($1)}')  
  x=$(echo "scale=4; $r*$th1" | bc | awk '{printf "%d", $1}') 
  y=$(echo "scale=4; $r*$th2" | bc | awk '{printf "%d", $1}') 
  x=$((x + r + 5))
  y=$((y + r + 5))
  tput cup $y $x
  printf "*"
done
tput cup $(tput lines) 0