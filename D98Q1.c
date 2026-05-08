/*Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.*/
#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

int compareIntervals(const void* a, const void* b) {
    struct Interval* i1 = (struct Interval*)a;
    struct Interval* i2 = (struct Interval*)b;
    if (i1->start != i2->start) {
        return i1->start - i2->start;
    }
    return i1->end - i2->end;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

void mergeIntervals(struct Interval intervals[], int n) {
    if (n <= 0) return;

    qsort(intervals, n, sizeof(struct Interval), compareIntervals);

    int index = 0;
    for (int i = 1; i < n; i++) {
        if (intervals[index].end >= intervals[i].start) {
            intervals[index].end = max(intervals[index].end, intervals[i].end);
        } else {
            index++;
            intervals[index] = intervals[i];
        }
    }

    for (int i = 0; i <= index; i++) {
        printf("[%d, %d] ", intervals[i].start, intervals[i].end);
    }
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Interval* intervals = (struct Interval*)malloc(n * sizeof(struct Interval));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    mergeIntervals(intervals, n);

    free(intervals);
    return 0;
}