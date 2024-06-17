#!/bin/bash

# Loop until the output contains "died"
while true; do
    # Execute the command and capture its output
	#output=$(./philo 200 800 200 200 5)
	if [ "$#" -lt 1 ]; then
    	echo "Usage: $0 <command> [arguments...]"
    	exit 1
	fi

	output=$("$@")
	echo "$output"
	echo '\n'
    # Check if the output contains the word "died"
    if echo "$output" | grep -q "died"; then
        # If "died" is found, break the loop
        echo "Detected 'died' in the output."
        break
    fi
done

