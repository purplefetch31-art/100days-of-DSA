#include <stdio.h>

int main() {
    int n, key;
    int comparisons = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[100];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &key);

    int found = -1;

    for (int i = 0; i < n; i++) {
        comparisons++; 
        if (arr[i] == key) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        printf("Key found at position %d\n", found + 1);
    } else {
        printf("Key not found\n");
    }

    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}
