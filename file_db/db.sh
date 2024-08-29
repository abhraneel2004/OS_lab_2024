FILE="db.txt"
insert(){
  flag=1
  read -p "Enter Roll: " roll
  lines=$(wc -l < $FILE)
  for((i=2; i<=lines; i++)); do
    troll=$(head -n $i $FILE| tail -n 1| cut -d "|" -f 2)
    if [[ $troll == $roll ]]; then
      flag=0
      break
    fi
  done
  if [[ $flag -eq 1 ]]; then
    read -p "Enter Name: " name
    read -p "Enter Marks: " marks
    echo "$name|$roll|$marks" >> $FILE
    echo "Insert Successful"
  else
    echo "Data Already Present"
    echo "Insert Unsuccessful"
  fi
  
}

update(){
  flag=0
  read -p "Enter Roll: " roll
  lines=$(wc -l < $FILE)
  for((i=1; i<=lines; i++)); do
    troll=$(head -n $i $FILE| tail -n 1| cut -d "|" -f 2)
    if [[ $troll == $roll ]]; then
      read -p "Enter New Name: " nname
      read -p "Enter New Marks: " nmarks
      echo "$nname|$troll|$nmarks" >> temp.txt
      flag=1
    else
      name=$(head -n $i $FILE| tail -n 1| cut -d "|" -f 1)
      marks=$(head -n $i $FILE| tail -n 1| cut -d "|" -f 3)
      echo "$name|$troll|$marks" >> temp.txt
    fi
  done
  mv temp.txt $FILE
  if [ $flag -eq 1 ]; then
    echo "Update Successful"
  else
    echo "No data about Roll no.: $roll found"
  fi
}

delete(){
  read -p "Enter the roll to delete: " roll
  grep -v "|$roll|" $FILE > temp.txt && mv temp.txt $FILE
}

display(){ cat $FILE && echo " "
}

while [ true ]; do
  printf "\n-----------------------\nOperations\n"
  echo "1. Insert"
  echo "2. Update"
  echo "3. Delete"
  echo "4. Display"
  echo "5. Exit"
  echo "~~~~~~~~~~~~~~~~~"
  read -p "Enter your choice: " choice
  case $choice in
    1) insert ;;
    2) update ;;
    3) delete ;;
    4) display ;;
    5) exit;;
    *) echo "Invalid choice" ;;
  esac
done