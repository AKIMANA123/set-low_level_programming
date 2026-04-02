# 0x0A. C - argc, argv

This program prints its own name using argv[0].

## Compilation

gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-whatsmyname.c -o mynameis

## Usage

./mynameis

Output: ./mynameis

## Rename and run

mv mynameis newname
./newname

Output: ./newname

## Code

#include <stdio.h>

int main(int argc, char *argv[])
{
    (void)argc;
    printf("%s\n", argv[0]);
    return (0);
}
