#include <stdio.h>

#define arrLen 50

void shift_element(int *arr, int i);

void printArray(const int arr[], int n);

void insertion_sort(int *arr, int len);

int main() {

    int arr[arrLen];
    for (int i = 0; i < arrLen; ++i) {
        scanf("%d", &arr[i]);
    }
    insertion_sort(arr, arrLen);
    printArray(arr, arrLen);
}

void shift_element(int *arr, int i) {
    for (int *p = arr + i - 1; p >= arr; p--) {
        *(p + 1) = *p;
    }
}

void insertion_sort(int *arr, int len) {
    int j;
    int temp;
    for (size_t i = 1; i < len; i++) {
        temp = *(arr + i);
        j = i - 1;
        while (j >= 0 && *(arr + j) > temp) {
            shift_element(arr + j, 1);
            j = j - 1;
        }
        *(arr + j + 1) = temp;
    }
}


void printArray(const int *arr, int n) {
    for (size_t i = 0; i < n - 1; i++) {
        printf("%d,", *(arr + i));
    }
    printf("%d", *(arr + n - 1));
    printf("\n");
}

