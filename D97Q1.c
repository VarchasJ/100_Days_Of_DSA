/*Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.*/
#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

int compareIntervals(const void* a, const void* b) {
    return ((struct Interval*)a)->start - ((struct Interval*)b)->start;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

void push(int heap[], int* size, int value) {
    heap[*size] = value;
    int i = *size;
    (*size)++;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void pop(int heap[], int* size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    minHeapify(heap, *size, 0);
}

int minMeetingRooms(struct Interval* intervals, int n) {
    if (n == 0) return 0;

    qsort(intervals, n, sizeof(struct Interval), compareIntervals);

    int* heap = (int*)malloc(n * sizeof(int));
    int heapSize = 0;

    push(heap, &heapSize, intervals[0].end);

    for (int i = 1; i < n; i++) {
        if (intervals[i].start >= heap[0]) {
            pop(heap, &heapSize);
        }
        push(heap, &heapSize, intervals[i].end);
    }

    int result = heapSize;
    free(heap);
    return result;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Interval* intervals = (struct Interval*)malloc(n * sizeof(struct Interval));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    printf("%d\n", minMeetingRooms(intervals, n));

    free(intervals);
    return 0;
}