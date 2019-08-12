#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* typedef of a function pointer, makes life a lot easier */
typedef int (*compare_cb)(int a, int b);

/**
 * A classic bbubble sirt function that uses the compare_cb to do the sorting
 * int *numbers is the same as int numbers[] but makes more clear
 * it is an array of integers
 */
static int *bubble_sort(int numbers[], int count, compare_cb cmp) {
    int temp = 0;
    int *target = malloc(count *sizeof(int));
    
    if(!target) {
        perror("malloc");
        exit(-errno);
    }
    
    memcpy(target, numbers, count * sizeof(int));
    
    for (int i = 0; i<count;i++) {
        for (int j = 0; j<count-1; j++) {
            if(cmp(target[j], target[j+1]) > 0) {
                temp = target[j+1];
                target[j+1] = target[j];
                target[j] = temp;
            }
        }
    }
    return target;
}

static int sorted_order(int a, int b) {
    return a - b; /* check if this is higer than 0 */
}

static int reverse_order(int a, int b) {
    return b - a;
}

static int strange_order(int a, int b) {
    if(a==0 || b==0) {
        return 0;
    }
    else {
        return a%b;
    }
}

void print_list(int *sorted, int count) {
    for(int i=0; i<count; i++) {
        printf("%d", sorted[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if(argc<2) {
        printf("usage %s 4 3 1 5 6\n", argv[0]);
        return -1;
    }
    int count = argc - 1;
    char **inputs = argv + 1;
    
    int *numbers = malloc(count *sizeof(int));
    if(!numbers) {
        perror("malloc");
        exit(-errno);
    }
    
    for(int i=0; i < count; i++) {
        numbers[i] = atoi(inputs[i]);
        /*We don't like atoi, because it returns the int 0 if it fails to convert
         * so we don't know if atoi failed or not */
    }
    
    print_list(bubble_sort(numbers, count, sorted_order), count);
    print_list(bubble_sort(numbers, count, reverse_order), count);
    print_list(bubble_sort(numbers, count, strange_order), count);
    
    free(numbers);
    return 0;
}
