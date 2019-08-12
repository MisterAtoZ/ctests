#include <stdio.h>

void increase() { 
    int integer = 1;
    static int static_integer = 1;

    integer += 1;
    static_integer += 1;
    printf("Integer = %d, static int = %d\n", integer, static_integer);
}

int main() {
    for (int i = 0; i<4; i++) {
        increase();
    }
}
