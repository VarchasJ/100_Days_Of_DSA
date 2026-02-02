/*Delete an Element from an Array

Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left*/

#include <stdio.h>
#include <stdlib.h>


int main(){

int n=5;
int *arr;
arr=(int*)malloc(n*sizeof(int));
int pos;


for(int i=0;i<n;i++){
printf("Enter %d element of array:",i);
    scanf("%d",&arr[i]);
}
printf("Array:");
for(int i=0;i<n;i++){
    printf("%d\t",arr[i]);
}

printf("Enter position to delete:");
scanf("%d",&pos);

if(pos<0 || pos>n){
    printf("INVALID POSITION!!");

}
else{
    for(int i=pos;i<n-1;i++){
        arr[i]=arr[i+1];
    }

n--;

printf("Array after deletion:");
for(int i=0;i<n;i++){
    printf("%d\t",arr[i]);
}
printf("\n");

}


free(arr);










    return 0;
}