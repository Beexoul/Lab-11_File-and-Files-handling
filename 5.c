/* 
Write a program create structure to read the name, author and price of books from the 
above file named “library.dat” and display the name and price of books whose price is 
greater than 300.
*/

#include <stdio.h>
#include <stdlib.h>

struct book {
    char name[50];
    char author[50];
    float price;
};

int main() {
    FILE *fp;
    fp = fopen("library.dat", "rb");
    if (fp == NULL) {
        printf("File not found\n");
        exit(1);
    }
    struct book b;
    printf("Name \t Price\n");
    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (b.price > 300) {
            printf("%s \t %f\n", b.name, b.price);
        }
    }
    fclose(fp);
    return 0;
}
