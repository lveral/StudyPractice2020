 #include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

void BubbleSort(int *array, int N)
{
	int i, j, fl;
	
	do
	{
		fl = 0;
		for (j = 0; j < (N - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				fl = 1;
			}
		}
	} while(fl);
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
	BubbleSort(arrayU, N); 
	t2 = clock(); 
	t3 = (t2-t1) / CLOCKS_PER_SEC; 
	printf("\nUnsorted array\nTIME: %f", t3);
	
	t1 = clock(); 
	BubbleSort(arrayR, N); 
	t2 = clock(); 
	t3 = (t2-t1) / CLOCKS_PER_SEC; 
	printf("\nReverse sorted array\nTIME: %f", t3);
	
	t1 = clock(); 
	BubbleSort(arrayS, N); 
	t2 = clock(); 
	t3 = (t2-t1) / CLOCKS_PER_SEC; 
	printf("\nSorted array\nTIME: %f", t3);
	
	free(arrayU);
	free(arrayR);
	free(arrayS);
	fclose(input);
	return 0;
}
