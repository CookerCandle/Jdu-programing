#include <stdio.h>

int main(void) {
    printf("[%d]\n", 123); //[123]
    printf("[%2d]\n", 123); //[123]
    printf("[%-2d]\n", 123); //[123]
    printf("[%02d]\n", 123); //[123]
    printf("[%.2d]\n", 123); //[123]
    printf("[%6.2d]\n", 123); //[  123]
    printf("[%-6.2d]\n", 123); //[123  ]

    return (0);
}