#include <stdio.h>

int main() {
    int p, q;
    scanf("%d", &p);

    int a[1000], b[1000];

    for(int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &q);

    for(int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    int i = 0, j = 0;

    // merge process
    while(i < p && j < q) {
        if(a[i] <= b[j]) {
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }

    // remaining elements
    while(i < p) {
        printf("%d ", a[i]);
        i++;
    }

    while(j < q) {
        printf("%d ", b[j]);
        j++;
    }

    return 0;
}