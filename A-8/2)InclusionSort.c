#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

void InclusionSort(int *array, int N)
{
	int i, index, value;
	
	for (i = 1; i < N; i++)
	{
		index = i;
		value = array[i];
		
		while ((index > 0) && (array[index - 1] > value))
		{
			array[index] = array[index - 1];
			index--;
		}
		array[index] = value;
	}
}

int main()
{
	FILE *input;
	
	if ((input = fopen("input.txt", "r")) == NULL)
	{
		printf("!ERROR!File not found!\n");
		return 0;
	}
	
	int *arrayU, *arrayR, *arrayS, N, i;
	double t1, t2, t3;
	
	fscanf(input, "%i", &N);
	printf("%i", N);
	
	arrayU = (int*)malloc(N * sizeof(int));
	arrayR = (int*)malloc(N * sizeof(int));
	arrayS = (int*)malloc(N * sizeof(int));
	
	for (i=0; i < N; i++)
	{
		arrayU[i] =  rand();
		arrayR[i] = N - i;
		arrayS[i] = i;
	}
	
	
	t1 = clock(); 
	InclusionSort(arrayU, N); 
	t2 = clock(); 
	t3 = (t2-t1) / CLOCKS_PER_SEC; 
	printf("\nUnsorted array\nTIME: %f", t3);

	
	t1 = clock(); 
	InclusionSort(arrayR, N); 
	t2 = clock(); 
	t3 = (t2-t1) / CLOCKS_PER_SEC; 
	printf("\nReverse sorted array\nTIME: %f", t3);

	
	t1 = clock(); 
	InclusionSort(arrayS, N); 
	t2 = clock(); 
	t3 = (t2-t1) / CLOCKS_PER_SEC; 
	printf("\nSorted array\nTIME: %f", t3);

	
	free(arrayU);
	free(arrayR);
	free(arrayS);
	fclose(input);
	return 0;
}
