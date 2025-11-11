#!/bin/bash
book="address.txt"
if [ ! -f "$book" ]; then
    touch "$book"
fi
while true 
do
    echo "Enter the choice given below"
    echo "1.seach entry"
    echo "2 enter a entry"
    echo "3 delete a entry"
    echo "4 quit"
    echo -n "Enter the choice"
    read choice

    case $choice in
        1) 
            echo -n "Enter to search"
            read key
            grep -i "$key" "$book" || echo "Not found";
            ;;
        2)
            echo -n "enter the id"
            read id
            echo -n "enter the name"
            read name
            echo -n "enter the phone number"
            read phone    
            echo "$id;$name;$phone" >> "$book"
            ;;
        3)
            echo -n "enter the key"
            read key
            grep -v "^$key;" "$book" > temp && mv temp "$book"
            ;;

        4)
            echo -n "exit"
            exit 0
            ;;
        *)
            echo "choice invalid"
            ;;
    esac
done                       
