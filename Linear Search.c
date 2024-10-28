#include <stdio.h>

int linearSearch(int* arr, int n, int key) {
  
    for (int i = 0; i < n; i++) {

        // If key is found, return key
        if (arr[i] == key) {
            return i;
        }
    }

    return -1;
}

int main() {
    int arr[] = { 10, 50, 30, 70, 80, 60, 20, 90, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    int i = linearSearch(arr, n, key);

    if (i == -1)
        printf("Key Not Found");
    else
        printf("Key Found at Index: %d", i);

    return 0;
}
