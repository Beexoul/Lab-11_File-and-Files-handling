/* Write a program to create “student.txt” file to store the above records for 10 students and 
display the records of student who are not from pokhara.
*/

#include <stdio.h>
#include <stdlib.h>

struct date {
int day;
int month;
int year;
};
struct student {
int roll_no;
char name[50];
char address[100];
char faculty[50];
struct date dob;
};

int main() {
FILE *file;
file = fopen("student.txt", "wb+");
if (file == NULL) {
printf("Error opening file\n");
    exit(1);
}

struct student students[10];
for (int i = 0; i < 10; i++) {
printf("Enter roll number of student %d: ", i + 1);
scanf("%d", &students[i].roll_no);
printf("Enter name of student %d: ", i + 1);
gets(students[i].name);
printf("Enter address of student %d: ", i + 1);
gets(students[i].address);
printf("Enter faculty of student %d: ", i + 1);
gets(students[i].faculty);
printf("Enter date of birth of student %d: ", i + 1);
scanf("%d/%d/%d", &students[i].dob.day, &students[i].dob.month, &students[i].dob.year);
fflush(stdin);
}
fwrite(students, sizeof(students), 10, file);
rewind(file);
printf("\nDisplaying the students:\n");
printf("Roll No \t Name \t Address \t Faculty \t DOB\n");
if(fread(students, sizeof(students), 10, file) == 1) {
for (int i = 0; i < 10; i++) {
if (strcmp(students[i].address, "Pokhara") != 0) {
printf("%d \t %s \t %s \t %s \t %d/%d/%d\n", students[i].roll_no, students[i].name, students[i].address, students[i].faculty, students[i].dob.day, students[i].dob.month, students[i].dob.year);
}
}
}
fclose(file);
return 0;
}