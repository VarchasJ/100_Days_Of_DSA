/*Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).*/
#include <stdio.h>
#include <stdlib.h>

struct Element {
    int val;
    int original_index;
};

void merge(struct Element arr[], int count[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    struct Element* L = (struct Element*)malloc(n1 * sizeof(struct Element));
    struct Element* R = (struct Element*)malloc(n2 * sizeof(struct Element));

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    int right_smaller_count = 0;

    while (i < n1 && j < n2) {
        if (L[i].val <= R[j].val) {
            count[L[i].original_index] += right_smaller_count;
            arr[k++] = L[i++];
        } else {
            right_smaller_count++;
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        count[L[i].original_index] += right_smaller_count;
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}

void mergeSort(struct Element arr[], int count[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, count, left, mid);
        mergeSort(arr, count, mid + 1, right);
        merge(arr, count, left, mid, right);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Element* arr = (struct Element*)malloc(n * sizeof(struct Element));
    int* count = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].val);
        arr[i].original_index = i;
    }

    mergeSort(arr, count, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");

    free(arr);
    free(count);
    return 0;
}