int maxSubarraySumCircular(int* nums, int numsSize) {
    int total = 0;
    
    int maxSum = nums[0], currMax = 0;
    int minSum = nums[0], currMin = 0;


    for(int i = 0; i < numsSize; i++) {
        total += nums[i];

        // normal max subarray (Kadane)
        currMax = (currMax > 0) ? currMax + nums[i] : nums[i];
        if(currMax > maxSum) maxSum = currMax;

        // min subarray
        currMin = (currMin < 0) ? currMin + nums[i] : nums[i];
        if(currMin < minSum) minSum = currMin;
    }

    // edge case: all negative
    if(maxSum < 0) return maxSum;

    // circular case
    int circular = total - minSum;


    return (maxSum > circular) ? maxSum : circular;
}