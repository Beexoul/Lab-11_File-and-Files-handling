/* 

Write a Program to open a new file and read name, address and telephone number of 10 
employees from a user and write to a file named “employee.txt” and now read from the 
file and display the information.

*/

#include <stdio.h>
#include <stdlib.h>

struct employee {
    char name[50];
    char address[100];
    char telephone[20];
};

int main() {
    FILE *file;
    file = fopen("employee.txt", "wb+");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    struct employee emp[10];
    for (int i = 0; i < 3; i++) {
        printf("Enter name of employee %d: ", i + 1);
        scanf("%s", emp[i].name);
        printf("Enter address of employee %d: ", i + 1);
        scanf("%s", emp[i].address);
        printf("Enter telephone number of employee %d: ", i + 1);
        scanf("%s", emp[i].telephone);  
    }
    fwrite(emp, sizeof(emp), 10, file);
    rewind(file);
    printf("\nDisplaying the employees:\n");
    printf("Name \t\t Address \t\t Telephone\n");
    fread(emp, sizeof(emp), 10, file);
    for (int i = 0; i < 3; i++) {
        printf("%s \t %s \t %s\n", emp[i].name, emp[i].address, emp[i].telephone);
    }
    fclose(file);
    return 0;
}