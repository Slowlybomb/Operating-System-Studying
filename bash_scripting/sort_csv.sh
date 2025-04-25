#!/bin/bash

FILE=$1
OUTPUT_FILE=$2

if [ ! -f "$FILE" ]; then
    echo "ERROR: File $FILE does not exist."
elif [ -z "$OUTPUT_FILE" ]; then 
    echo "ERROR: Output filename not provided."
elif [ -f "$OUTPUT_FILE" ]; then
    echo "ERROR: Output file already exists."
else
    touch "$OUTPUT_FILE"
    head -n 1 "$FILE" >> "$OUTPUT_FILE"
    tail -n +2 "$FILE" | sort -t, -k2,2g >> "$OUTPUT_FILE"
fi

echo "--- PROGRAM ENDS ---"
