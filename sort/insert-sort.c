#include <stdio.h>

int insertionSort(int *arry, int n_size) {

    int i, j, key;
    if (arry == NULL) return -1;

    for (i = 1; i < n_size; i++) {
        key = *(arry + i);
	j = i -1 ;
	while (j >= 0 && *(arry + j) > key) {
	    *(arry + j + 1) = *(arry + j);
	    j --;
        }
    *(arry + j + 1) = key;
    }

    return 0;
}


void printArray(int *arry, int n) { 

    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arry[i]); 
    printf("\n"); 
} 

int main() {

    int arry[] = {12, 7, 11, 13, 5, 6, 6};
    int n = sizeof(arry)/sizeof(arry[0]);

    insertionSort(arry, n);
    printArray(arry, n);
    return 0; 
}
