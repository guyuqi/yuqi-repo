#include <stdio.h>
#include <stdlib.h>

/* n persons; 
 *score range: 0~x;
 * O(n)
 */
int counting_sort(int *a, int size_n) {

	if ((size_n <= 1) || (a == NULL)) return -1;

	/* max: counting group */
	int max = *a;
	int i,j;
	for (i = 1; i < size_n; ++i) {
		if (*(a + i) > max)
		max = *(a + i);
	}
	
	int *ct_gp = (int *)malloc(max + 1);
	if (ct_gp == NULL) return -1;

	int *sorted_arry = (int *)malloc(size_n);
	if (sorted_arry == NULL) return -1;

	for (i = 0; i < max + 1; i++)
		*(ct_gp + i) = 0;

	for (i = 0; i < size_n; i++)
		*(ct_gp + *(a + i)) += 1;

	for (i = 1; i < max + 1; i++) {
		*(ct_gp + i) += *(ct_gp + i -1); 
	}

	for (j = size_n - 1; j >= 0; j--) {
		*(sorted_arry + *(ct_gp + *(a + j)) - 1) = *(a + j);
		*(ct_gp + *(a + j)) -= 1;
	}

	/* Update the source array a */
	for (i = 0; i < size_n; i++)
		*(a + i) = *(sorted_arry + i);

	return 0;
}


int main() {

	int score[20] = {1,7,0,3,6,5,4,2,1,1,6,4,5,3,2,1,6,8,2,4};

	int rt = counting_sort(score, 20);
	if (rt)
		return -1;
	else {
		for (int i = 0; i < 20; i++)
			printf("%4d ",score[i]);
		printf("\n");
		return 0;
	}
}
