#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
        struct node *rootnode;
        /*This will point to each node as it traverses the list*/
        struct node *nextnode;
        rootnode = malloc(sizeof(struct node));
        /*This allocates the rootnode memory*/
        rootnode->next = 0;
        rootnode->data = 666;
        /*Now we use the next node struct to go over the linked list*/
        nextnode = rootnode;
        /*now we traverse the list*/
        if(nextnode !=0) {
                while(nextnode->next != 0) {
                        nextnode = nextnode->next;
                }
        }
        /*Creates a node at the end of the list*/
        nextnode->next = malloc(sizeof(struct node));
        nextnode = nextnode->next;
        
        if(nextnode==0) {
                printf("Out of memory");
                return 0;
        }
        /*Add the next node at the end of the (small) list*/
        nextnode->next = 0;
        nextnode->data = 43;
        
        return 0;
}
