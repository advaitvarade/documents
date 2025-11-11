#!/bin/bash
book="phoneBook.txt"

if [ ! -f "$book" ]; then
    touch "$book"
fi

while true
do
    echo  "Enter the choice"
    echo  "1.add new number"
    echo  "2.display all values"
    echo  "3.sort phone book my name"
    echo  "4.Delete the entry"
    echo "5.edit entry"
    read choice
    case "$choice" in
        1)
            echo "Enter the name"
            read name
            echo "Enter the phone number"
            read phone
            echo "$name:$phone" >> "$book"
            ;;
        2)
            echo "enter name or phone number"
            read key
            grep -iw "$key" "$book"|| echo "not found"
            ;;
        3)
            echo "sorted by name"
            sort -k2 "$book" -o "$book"
            ;;
        4)
            echo "Enter the name"
            read name
            grep -vw "$name" "$book"> temp && mv temp "$book"
            ;;
        5)
            echo "Enter the key"
            read key
            grep -vw "$key" "$book" > temp && mv temp "$book"
            echo "Enter the changed name"
            read name    
            echo "enter changed phone number"
            read phone
            while  [ ${#phone} -ne 10 ];do
                echo "ps enter the phone number again 10 digit"
                read phone
            done
            echo "$name:$phone" >> "$book"
            ;;
        *)
            echo "invalide choice"    
            ;;
    esac
done            

