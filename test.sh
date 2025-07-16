#!/bin/bash

PROGRAM="./so_long"        # Replace with your actual program path
INVALID_MAP_DIR="./test"     # Directory containing files
TRACE="trace.txt"
SEARCH_STRING="Error"
OUTPUT_FILE="output.txt"

# Loop through all files in the directory
echo > $TRACE
for file in "$INVALID_MAP_DIR"/*; do
    if [ -f "$file" ]; then
        echo "Running: $PROGRAM $file"
        
        # Run the program with the file as an argument
        $PROGRAM "$file" 2> "$OUTPUT_FILE"
		cat $OUTPUT_FILE >> $TRACE
		if grep -q "$SEARCH_STRING" "$OUTPUT_FILE"; then
		    echo "✅ Output contains: '$SEARCH_STRING'"
		else
		    echo "❌ Output does NOT contain: '$SEARCH_STRING'"
		    exit 0
		fi
    fi
	
done
