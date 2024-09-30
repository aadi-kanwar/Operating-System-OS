//Best Fit and First Fit algorithm
// 23.09.2024

#include<stdio.h>
#include<stdlib.h>
#define MAX_BLOCKS 10
typedef struct {
    int sizee;
    int is_allocated;
}MemoryBlock;

void first_fit(MemoryBlock blocks[], int num_blocks, int request_size){
    for (int i = 0; i < num_blocks; i++)
    {
        if (!blocks[i].is_allocated && blocks[i].sizee >= request_size){
            blocks[i].is_allocated = 1;
            printf("First Fit: Allocated %d bytes at Block %d\n", request_size, i);
            return;
        }
    }
    printf("First Fit: No suitable block found for %d bytes\n", request_size);
}

void best_fit(MemoryBlock blocks[], int num_blocks, int request_size){
    int best_index = -1;
    for(int i = 0; i < num_blocks; i++){
        if (!blocks[i].is_allocated && blocks[i].sizee >= request_size){
            if (best_index == -1 || blocks[i].sizee < blocks[best_index].sizee){
                best_index = i;
            }
        }
    }
    if (best_index != -1){
        blocks[best_index].is_allocated = 1;
        printf("Best Fit: Allocated %d bytes at Block %d\n", request_size, best_index);
    }else{
        printf("Best Fit: No suitable block found for %d bytes\n", request_size);
    }

}

void print_memory_blocks(MemoryBlock blocks[], int num_blocks){
    printf("Memory Blocks:\n");
    for (int i = 0; i < num_blocks; i++){
        printf("Block %d: Size: %d, Allocated: %s\n", i, blocks[i].sizee, blocks[i].is_allocated ? "Yes" : "No"); 
    }
}

int main(){
    MemoryBlock blocks[MAX_BLOCKS] = {
        {100, 0},
        {500, 0},
        {200, 0},
        {300, 0},
        {600, 0},
        {700, 0},
        {900, 0},
        {100, 0},
        {200, 0},
        {50, 0}
    };
    int num_blocks = MAX_BLOCKS;
    print_memory_blocks(blocks, num_blocks);
    //Request memory allocation
    first_fit(blocks, num_blocks, 212);
    first_fit(blocks, num_blocks, 417);
    best_fit(blocks, num_blocks, 112);
    best_fit(blocks, num_blocks, 25);
    print_memory_blocks(blocks, num_blocks);

    print_memory_blocks(blocks, num_blocks);
    return 0;
}