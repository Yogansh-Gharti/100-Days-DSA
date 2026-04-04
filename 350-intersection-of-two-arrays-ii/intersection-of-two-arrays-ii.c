int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int freq[1001] = {0};

    // nums1 ka frequency count
    for(int i = 0; i < nums1Size; i++) {
        freq[nums1[i]]++;
    }

    int* result = (int*)malloc(1000 * sizeof(int));
    int k = 0;

    // nums2 check karo
    for(int i = 0; i < nums2Size; i++) {
        if(freq[nums2[i]] > 0) {
            result[k++] = nums2[i];
            freq[nums2[i]]--;
        }
    }

    *returnSize = k;
    return result;
}