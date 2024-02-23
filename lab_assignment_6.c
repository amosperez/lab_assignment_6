#include <stdio.h>
#include <stdlib.h>



int search(int numbers[], int low, int high, int value) 
{
	int midpoint = (low+high)/2;

	if(low>high){
		return -1;

	} else if (numbers[midpoint]==value){
		return midpoint;

	} else if (numbers[midpoint]>value) {
		return search(numbers, low, midpoint-1, value);
		
	} else {
		return search(numbers, midpoint+1, high, value);
	}
}




void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
// 3 -- numInputs
// 6 -- countOfNums
// 1 3 4 6 7 9 -- numArray[value]
// 4 -- countOfNums
// 2 5 7 8 -- numArray[value]
// 32 -- countOfNums
// 1 2 3 4 5 6 7 7 8 9 10 14 16 17 19 19 20 23 24 27 29 30 32 34 37 39 39 49 50 55 60 62 -- numArray[value]


	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}