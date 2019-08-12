#include <stdlib.h>
#include <linux/random.h>

int main(void) {
    int random = getrandom(void *buf, size_t buflen, unsigned int flags);
    printf("Het random nummer is: %d\n", random);
}
