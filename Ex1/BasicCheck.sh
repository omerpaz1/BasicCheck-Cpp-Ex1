#!/bin/bash
fileTest=./makefile
folderName=$1
execute=$2
noneed=$3
cd $folderName
if [ -e "$folderName/$fileTest" ] 
then
make
    if [ $? -gt 0 ] 
        then
        echo "Error Compilation"
        exit 7
    fi
echo "Succes Compilation "
valgrind --leak-check=full -v ./$execute > memoryleaks.txt 2>&1
grep -q "no leaks are possible"  memoryleaks.txt
    if [ $? -eq 0 ] 
    then
        echo "Memory leaks Sucess"
        rm memoryleaks.txt  
        valgrind --tool=helgrind $folderName/$execute > Threadcheck.txt 2>&1
        grep -q "ERROR SUMMARY: 0 errors" Threadcheck.txt
            if [ $? -eq 0 ] 
            then
                echo "Thread Race Succes"
                rm Threadcheck.txt 
                exit 0
                else 
                    echo "Thread Race Failed"
                    rm Threadcheck.txt
                    exit 1
             fi
    else
        echo "Memory Leak Failed"
        rm memoryleaks.txt
        valgrind --tool=helgrind $folderName/$execute > Threadcheck.txt 2>&1
        grep -q "ERROR SUMMARY: 0 errors" Threadcheck.txt
            if [ $? -eq 0 ] 
            then
                echo "Thread  Succes"
                rm Threadcheck.txt 	
                exit 2	
                else
                    echo "Thread Failed"
                    rm Threadcheck.txt 
                    exit 3
            fi
    fi 
else 
echo "Failed arguments"
exit 7 
fi 


