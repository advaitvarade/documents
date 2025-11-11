#!/bin/bash

while true 
do 
    echo "Enter the choice"
    echo "1.if file exists"
    echo "2.read a file"
    echo "3 delete a file"
    echo "4. Display list of files"
    read choice 
    case $choice in 
        1)
            echo "enter the file name"
            read filename
            if [ -f $filename ];then 
                echo "file exists"
            else
                echo "file do not exists"
            fi
            ;;
        2)
            echo "enter the file name to read"
            read filename
            if [ -f $filename ];then 
                cat "$filename"
            else
                echo "file not found"
            fi
            ;;
        3)
            echo "enter the file name to delete"
            read filename
            if [ -f $filename ];then 
                rm "$filename"
            else 
                echo "file not found"  
            fi              
            ;;
        4)
            ls 
            ;;
        *)
            echo "invalid choice"
            ;;     
    esac
done    