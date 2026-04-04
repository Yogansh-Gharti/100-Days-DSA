#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    k = k % n; // handle large k

    int temp[1000];
    int index = 0;

    // last k elements
    for(int i = n - k; i < n; i++) {
        temp[index++] = arr[i];
    }

    // remaining elements
    for(int i = 0; i < n - k; i++) {
        temp[index++] = arr[i];
    }

    // print result
    for(int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }

    return 0;
}