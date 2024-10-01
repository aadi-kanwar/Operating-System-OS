//Producer Consumer Problem using Semaphore (Arrays) and Mutex Locks
//26.08.2024
#include<stdio.h>
#include<stdlib.h>

//Initialising the mutex to 1
int mutex = 1;

//Initialising the number of full slots to 0
int full = 0;

//Number of empty slots as buffer size
int empty = 3, x = 0;

//Funtion to produce an item and add it to the buffer.
void producer()
{
    //Decrease empty value by 1
    --empty;
    //Increase the number of full slots by 1
    ++full;
    //Decrease the number of empty slots by 1
    --mutex;

    //Item Produced.
    x++;
    printf("Producer produces item %d\n", x);
    //Increase mutex value by 1
    ++mutex;
}

//Function to consume an item and remove it from the buffer.
void consumer()
{
    //Decrease the number of full slots by 1
    --full;
    //Increase the number of empty slots by 1
    ++empty;
    //Decrease the mutex value by 1
    --mutex;

    //Item Consumed.
    printf("Consumer consumes item %d\n", x);
    x--;
    //Increase the mutex value by 1
    ++mutex;
}

int main()
{
    int n,i;
    printf("1. Press 1 for Producer\n2. Press 2 for Consumer\n3. Press 3 for Exit\n");

for(i = 1; i > 0; i++)
{
    printf("Enter your choice: ");
    scanf("%d", &n);

    //Switch case to choose the producer or consumer function
    switch(n)
    {
        case 1: //If mutex is 1 and empty is not 0, then producer will produce an item
                if((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("Buffer is full!\n");
                break;
        case 2: //If mutex is 1 and full is not 0, then consumer will consume an item
                if((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("Buffer is empty!\n");
                break;
        case 3: printf("Exiting...");
                exit(0);
                break;
    }
}
    return 0;
}