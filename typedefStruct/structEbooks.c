#include <stdio.h>
#include <string.h>

struct eBooks{ //typedef zorgt ervoor dat eBooks vast een struct isen er niet overal nog struct voor moet staan
        char title [128];
        char author[128];
        int book_id;
};
//"Bad way of doing this, the method below is how it should be done
 /*declaring the functions*/
 /*
void printeBook( struct eBooks ebook) {
        printf("Title: %s\n", ebook.title);
        printf("Author: %s\n", ebook.author);
        printf("ISBN: %d\n", ebook.book_id);
}

int main(void) {
        struct eBooks eBook1;
        struct eBooks eBook2;
        strncpy(eBook1.title, "Linux C Programming", sizeof(eBook1.title));
        strncpy(eBook1.author, "Jasper Nuyens", sizeof(eBook1.author));
        eBook1.book_id = 39214;
        strncpy(eBook2.title, "Embedded Linux Development", sizeof(eBook2.title));
        strncpy(eBook2.author, "Jasper Nuyens", sizeof(eBook2.author));
        eBook2.book_id = 39215;
        printeBook(eBook1);
        printeBook(eBook2);
        return 0;
}*/

 typedef struct { //typedef zorgt ervoor dat eBooks vast een struct isen er niet overal nog struct voor moet staan
        char title [128];
        char author[128];
        int book_id;
} eBook;
 
/*declaring the functions*/
void printeBook(eBook *ebook) {
        printf("Title: %s\n", ebook->title);
        printf("Author: %s\n", ebook->author);
        printf("ISBN: %d\n", ebook->book_id);
}

int main(void) {
        eBook eBook1;
        eBook eBook2;
        strncpy(eBook1.title, "Linux C Programming", sizeof(eBook1.title));
        strncpy(eBook1.author, "Jasper Nuyens", sizeof(eBook1.author));
        eBook1.book_id = 39214;
        strncpy(eBook2.title, "Embedded Linux Development", sizeof(eBook2.title));
        strncpy(eBook2.author, "Jasper Nuyens", sizeof(eBook2.author));
        eBook2.book_id = 39215;
        
        /*Passing the address of ebook1 and ebook2*/
        printeBook(&eBook1);
        printeBook(&eBook2);
        return 0;
}
