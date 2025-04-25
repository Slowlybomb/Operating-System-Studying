#!/bin/bash

FILE=$1

if [ ! -f "$FILE" ]; then
    echo "ERROR: File $FILE does not exist."
else
    tail -n +2 "$FILE" | while IFS=, read -r ID timeSec temp pressure; do
        time=$(date -r "$timeSec" '+%Y-%m-%d %H:%M:%S') 
        echo "ID: $ID, Time: $time, Temperature: $temp, Pressure: $pressure"
    done
fi

echo "--- PROGRAM ENDS ---"
