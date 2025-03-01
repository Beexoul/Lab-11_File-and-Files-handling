/*
Write a program create structure to read the name, author and price of 200 books in a 
library and store the information into file “library.dat”.
*/
#include <stdio.h>
#include <stdlib.h>
    struct book
    {
        char name[50];
        char author[50];
        float price; 
    };
int main(){
struct book b[200];
int i;
FILE *fp;
fp=fopen("library.dat","wb");
if(fp==NULL){
    printf("File not found\n");
    exit(1);
}
printf("Enter the details of 200 books:\n");
for(i=0;i<2;i++){
    printf("Enter the name of book %d: ",i+1);
    gets(b[i].name);
    printf("Enter the author of book %d: ",i+1);
    gets(b[i].author);
    printf("Enter the price of book %d: ",i+1);
    scanf("%f",&b[i].price);
    fflush(stdin);
}
fwrite(&b,sizeof(b),200,fp);
fclose(fp);
return 0;
}