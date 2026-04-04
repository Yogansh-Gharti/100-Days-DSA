void moveZeroes(int* nums, int numsSize) {
    int k = 0;

    // non-zero elements ko aage shift karo
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != 0) {
            nums[k++] = nums[i];
        }
    }

    // baaki sab 0 fill karo
    while(k < numsSize) {
        nums[k++] = 0;
    }
}