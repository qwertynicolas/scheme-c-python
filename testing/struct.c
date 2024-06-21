//struct

#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[25];
    char major[25];
    int age;
    double gpa;
};

int main() {

    struct Student student1;
    student1.age = 22;
    student1.gpa = 3.2;
    int strcpy(student1.name, "John");
    int strcpy(student1.major, "Math");

    struct Student student2;
    student2.age = 23;
    student2.gpa = 3.6;
    strcpy(student2.name, "Joe");
    strcpy(student2.major, "Economics");

    printf("%s\n", student2.name);
    printf("%s\n", student2.major);
    printf("%d\n", student2.age);
    printf("%.2f", student2.gpa);

    printf("\t%s\n", student1.name);
    printf("\t%s\n", student1.major);
    printf("\t%d\n", student1.age);
    printf("\t%.2f\n", student1.gpa);

    return 0;
}
