#include <stdio.h>

int main(void) {
    printf("[%d]\n", 123); //[123]
    printf("[%6d]\n", 123); //[   123]
    printf("[%-6d]\n", 123); //[123   ]
    printf("[%06d]\n", 123); //[000123]
    printf("[%.4d]\n", 123); //[0123]
    printf("[%6.4d]\n", 123); //[  0123]
    printf("[%-6.4d]\n", 123); //[0123  ]

    return (0);
}