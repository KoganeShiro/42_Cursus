
#!/bin/bash

while true; do
	if [ "$#" -lt 1 ]; then
    	echo "Usage: $0 <command> [arguments...]"
    	exit 1
	fi

	output=$("$@")
	echo "$output"
	echo
    if echo "$output" | grep -q "died"; then
		after_died=$(echo "$output" | sed -n '/died/,$p' | sed '1d')
        if [ -n "$after_died" ]; then
            echo "Detected additional output after 'died':"
            echo "$after_died"
            break
		fi
    fi
done
