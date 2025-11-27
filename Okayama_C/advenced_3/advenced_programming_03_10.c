#include <stdio.h>

void func (int a, int b) {
    a = a + 1;
    b = b * 2;
    printf("func: a = %d, b = %d\n", a, b);
}

int main() {
    int x = 10, y = 20;
    func(x, y);
    printf("main: x = %d, y = %d", x, y);

    return 0;
}