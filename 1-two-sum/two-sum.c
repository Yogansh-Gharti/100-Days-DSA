#include <stdio.h>
#include <stdlib.h>

#define SIZE 10007  // prime number for better hashing

typedef struct {
    int key;
    int value;
} Hash;

Hash hashTable[SIZE];

// Initialize
void init() {
    for(int i = 0; i < SIZE; i++) {
        hashTable[i].key = 1000000001; // dummy value (out of constraints)
    }
}

// Hash function (handles negative numbers)
int hashFunc(int key) {
    int index = key % SIZE;
    if(index < 0) index += SIZE;
    return index;
}

// Insert
void insert(int key, int value) {
    int index = hashFunc(key);
    
    while(hashTable[index].key != 1000000001) {
        index = (index + 1) % SIZE;
    }
    
    hashTable[index].key = key;
    hashTable[index].value = value;
}

// Search
int search(int key) {
    int index = hashFunc(key);
    int start = index;

    while(hashTable[index].key != 1000000001) {
        if(hashTable[index].key == key)
            return hashTable[index].value;

        index = (index + 1) % SIZE;

        if(index == start) break; // prevent infinite loop
    }
    return -1;
}

// Main function
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    init();
    
    int* result = (int*)malloc(2 * sizeof(int));
    
    for(int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        
        int index = search(complement);
        
        if(index != -1) {
            result[0] = index;
            result[1] = i;
            *returnSize = 2;
            return result;
        }
        
        insert(nums[i], i);
    }
    
    *returnSize = 0;
    return NULL;
}