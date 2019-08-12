#include <stdio.h>

int sum(int number);
int main() {
    int number, add;
    printf("Enter which number is the Fibonacci sequence you want:\n");
    scanf("%d", &number); //Damn, we really shouldnt use scanf!, but we dit loll */
    add = sum(number);
    printf("sum=%d",add);
}

int sum(int number) {
    if(number==0) {
        return number;
    }
    else {
        return number+sum(number-1); /*selfcall to function sum()*/
    }
}
