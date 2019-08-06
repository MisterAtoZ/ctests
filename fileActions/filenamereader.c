#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define fileName "testfile.txt"
#define stringSize 200
#define writeChar "Dit is er toegevoegd in de file!"

int main(void) 
{
    FILE *fp;
    char content[stringSize];
    /* FIRST READ */
    fp = fopen(fileName, "r");
    
    if(fp==NULL) {
        printf("System call returns error: %s\n", strerror(errno));
        return 1;
    }

    //fread(content,stringSize,1,fp);
    fgets(content, stringSize, fp);

	// printf("De file: %s bevat de volgende inhoud:\n", fileName);
    // for(int i=0; i<stringSize; i++) {
    //     printf("%c", content[i]);
    // }
    printf("in de file zit: \n");
    printf("%s\n", content);

    fclose(fp);
    printf("nu wordt er iets weggeschreven in de file\n");

    /* WRITE NEW TEXT */
    fp = fopen(fileName, "w"); //met de a, wordt er op het einde van de file toegevoegd
    if(fp==NULL) {
        printf("System call returns error: %s\n", strerror(errno));
        return 1;
    }
    fputs(writeChar, fp);
    fclose(fp);

    /* READ OUT TO DETECT THE CHANGE */
    printf("de file wordt opnieuw uitgelezen\n");
    fp = fopen(fileName, "r");
    
    if(fp==NULL) {
        printf("System call returns error: %s\n", strerror(errno));
        return 1;
    }

    //fread(content,stringSize,1,fp);
    fgets(content, stringSize, fp);

	// printf("De file: %s bevat de volgende inhoud:\n", fileName);
    // for(int i=0; i<stringSize; i++) {
    //     printf("%c", content[i]);
    // }
    printf("in de file zit: \n");
    printf("%s\n", content);

    fclose(fp);

	return 0;
}