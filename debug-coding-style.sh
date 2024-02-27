#!/bin/bash

set -x  # Enable command tracing

# Print the current directory and list its contents
pwd
ls -la

# Call the coding-style.sh script with all the arguments passed to this script
./coding-style.sh "$@"