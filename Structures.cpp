// Program to showcase the use of structures in C++ programming.
// 12.08.2024

#include<stdio.h>
#include<string.h>

struct Person 
{
    char name[50];
    int citNo;
    float salary;
}person1;


int main()
{
    // assign value to name of person1
    strcpy(person1.name, "Aadi Kanwar");
    //assign values to other person1 variables
    person1.citNo = 1973;
    person1.salary = 25000;
    //print struct variables
    printf("Name: %s\n", person1.name);
    printf("Citizenship Number: %d\n", person1.citNo);
    printf("Salary: %.2f\n", person1.salary);
    return 0;
}