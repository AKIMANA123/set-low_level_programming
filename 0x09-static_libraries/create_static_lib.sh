#!/bin/bash
# Script to create a static library called liball.a from all .c files

# Compile all .c files into object files
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 -c *.c

# Create static library from all object files
ar -rc liball.a *.o

# Index the library
ranlib liball.a

# Clean up object files (optional - comment out if you want to keep them)
# rm -f *.o
