// Program to showcase the use of array of structures in C++ programming.
// 12.08.2024

#include<stdio.h>
#include<string.h>

struct Employee 
{
    char empname[50];
    int empID;
    float salary;
};

void print(struct Employee emp)
{
    printf("Name: %s\n", emp.empname);
    printf("Employee ID: %d\n", emp.empID);
    printf("Salary: %.2f\n", emp.salary);
    printf("*****************\n");
}

int main()
{
    // declare an array of structures
    struct Employee emp[3];
    // Employee 1
    strcpy(emp[0].empname, "Aadi Kanwar");
    emp[0].empID = 1973;
    emp[0].salary = 25000;
    // Employee 2
    strcpy(emp[1].empname, "Rajat Sharma");
    emp[1].empID = 1974;
    emp[1].salary = 30000;
    // Employee 3
    strcpy(emp[2].empname, "Rahul Singh");
    emp[2].empID = 1975;
    emp[2].salary = 35000;
    // print the details of all employees
    for (int i = 0; i < 3; i++)
    {
        print(emp[i]);
    }
    return 0;
}