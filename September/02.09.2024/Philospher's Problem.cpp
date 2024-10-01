// Write a C++ program to solve the Philosopher's Problem using semaphores.
// 02.09.2024

#include<stdio.h>
#include<stdlib.h>

int sticks[5] = {1, 1, 1, 1, 1};
int mutex = 1;
int phil = 5;
int eat[5] = {0, 0, 0, 0, 0};

void pick_chopsticks(int phil)
{
    if (eat[phil] == 1)
    {
        printf("Philosopher %d is already eating. They cannot pick up chopsticks again\n", phil+1);
    }
    else if (sticks[phil] == 1 && sticks[(phil + 1) % phil] == 0)
    {
        sticks[phil] = sticks[(phil+1% phil)]=0;
        eat[phil] = 1;
        printf("Philosopher %d picks up chopsticks %d and %d\n",phil+1, phil+1, (phil+1)%phil+1);
        printf("Philosopher %d is eating\n", phil+1);
    }
    else
    {
        printf("Philosopher %d is waiting for chopsticks\n", phil+1);
    }
    ++mutex;
}

void put_chopsticks(int phil)
{
    --mutex;
    if(eat[phil] == 1)
    {
        sticks[phil] = sticks[(phil+1)%phil] = 1;
        eat[phil] = 0;
        printf("Philosopher %d puts down chopsticks %d and %d\n", phil+1, phil+1, (phil+1)%phil+1);
        printf("Philosopher %d is done eating\n", phil+1);
    }
    else
    {
        printf("Philosopher %d cannot put down chopsticks as they are not holding any\n", phil+1);
    }
    ++mutex;
}
int main()
{
    int choice, phil;
    printf("1. Pick up chopsticks\n2. Put down chopsticks\n3. Exit\n");
    while(1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the philosopher number (1-5): ");
                scanf("%d", &phil);
                if(phil < 1 || phil > 5)
                {
                    printf("Invalid philosopher number\n");
                }
                else
                {
                    pick_chopsticks(phil-1);
                }
                break;
            case 2:
                printf("Enter the philosopher number (1-5): ");
                scanf("%d", &phil);
                if(phil < 1 || phil > 5)
                {
                    printf("Invalid philosopher number\n");
                }
                else
                {
                    put_chopsticks(phil-1);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}