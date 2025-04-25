#!/bin/bash

FILE="$1"
OUTPUT_FILE="$2"

if [ ! -f "$FILE" ]; then
    echo "ERROR: File $FILE does not exist."
elif [ -z "$OUTPUT_FILE" ]; then 
    echo "ERROR: Output filename not provided."
elif [ -f "$OUTPUT_FILE" ]; then
    echo "ERROR: Output file already exists."
else
    touch "$OUTPUT_FILE"

    tail -n +2 "$FILE" | while IFS=, read -r ID timeSec temp pressure; do
        if (( $(echo "$temp < 1000" | bc -l) )); then
            echo "$ID,$timeSec,$temp,$pressure" >> "$OUTPUT_FILE"
            echo "$ID,$timeSec,$temp,$pressure"
        fi
    done

    echo "Filtered rows written to $OUTPUT_FILE"
fi

echo "--- PROGRAM ENDS ---"
