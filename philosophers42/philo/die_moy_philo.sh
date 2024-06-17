#!/bin/bash

# Check if at least one argument is provided
if [ "$#" -lt 1 ]; then
    echo "Usage: $0 <command> [arguments...]"
    exit 1
fi

# Number of times to run the full test
TOTAL_RUNS=100

# Initialize counters
total_deaths=0
total_iterations=0

# Run the test TOTAL_RUNS times
for (( run=1; run<=TOTAL_RUNS; run++ )); do
    echo "Starting run #$run..."
    iteration_count=0

    # Loop until the output contains "died"
    #while true; do
        # Execute the command with the provided arguments and capture its output
        output=$("$@")
        iteration_count=$((iteration_count + 1))

        # Check if the output contains the word "died"
        if echo "$output" | grep -q "died"; then
            # If "died" is found, increment the death counter and break the loop
            echo "Detected 'died' in the output on iteration $iteration_count."
            total_deaths=$((total_deaths + 1))
            total_iterations=$((total_iterations + iteration_count))
            #break
        fi
    #done
done

# Calculate the average number of iterations before "died"
average_iterations=$(echo "scale=2; $total_iterations / $total_deaths" | bc)

# Output the results
echo "Total runs: $TOTAL_RUNS"
echo "Total deaths: $total_deaths"
echo "Average iterations before 'died': $average_iterations"

