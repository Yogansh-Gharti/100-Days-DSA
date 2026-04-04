#include <stdlib.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);

    int maxSize = numsSize * numsSize;  // safe upper bound
    int** result = (int**)malloc(maxSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxSize * sizeof(int));

    int count = 0;

    for(int i = 0; i < numsSize - 2; i++) {
        if(i > 0 && nums[i] == nums[i - 1]) continue;

        int left = i + 1;
        int right = numsSize - 1;

        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if(sum == 0) {
                result[count] = (int*)malloc(3 * sizeof(int));
                result[count][0] = nums[i];
                result[count][1] = nums[left];
                result[count][2] = nums[right];
                (*returnColumnSizes)[count] = 3;
                count++;

                while(left < right && nums[left] == nums[left + 1]) left++;
                while(left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            }
            else if(sum < 0) left++;
            else right--;
        }
    }

    *returnSize = count;
    return result;
}