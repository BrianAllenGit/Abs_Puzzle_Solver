

// classwork.cpp : Defines the entry point for the console application.
//

# include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <time.h>


void change (char *x, char *y)  //This whole function just takes the two positions, and flips them.
{ 
	char temp; 
	temp = *x; 
	*x = *y; 
	*y = temp; 
} 
void permutations(char *numbers, int i, int n, int*num) 
{ 
	if (i == n) 
	{
		for (int k = 0; k < 10; k++)
		{
			num[k] = numbers[k] -48;
			if (num[k] == 0)
			{
				num[k] = 10;
			}
		}
		if (abs(num[0] - num[1]) == num[4] && abs(num[1] - num[2]) == num[5] && abs(num[2] - num[3]) == num[6] && abs(num[4] - num[5]) == num[7] && abs(num[5] - num[6]) == num[8] && abs(num[7] - num[8]) == num[9])
		{
			for (int i = 0; i < 10; i++)
			{
				printf("%d ", num[i]);
				if (i == 3)
				{
					printf("\n ");
				}
				if (i == 6)
				{
					printf("\n  ");
				}
				if (i == 8)
				{
					printf("\n  ");
				}
			}
			printf("\n\n");
		}
	}
	else 
	{ 
		for (int j = i; j <= n; j++) //Take this loop really slow, over and over many times. Step by step if you can.  
		{ 
			change((numbers+i), (numbers+j)); //This swaps the outermost numbers once the array is full
			permutations(numbers, i+1, n, num); //This line is the recursion, it starts the function over starting at the next index of the character array. Watch the values of n and i. 
			change((numbers+i), (numbers+j)); // 
		} 
	} 
} 
int main() 
{ 
	char numbers[] = "0123456789";  // This is just the numbers 0-9, I can't use 10 so we will need to work that out.
	int num[10];
	double runtime;
	clock_t start, end;
	start = clock();
	permutations(numbers, 0, 9, num); //This is sending the entire character array, the index of the array to start at, and the index to stop at.
	end = clock();
	runtime = ((end - start) / (double) CLOCKS_PER_SEC );
	printf ("Run time is %g seconds\n", runtime);
	return 0; 
}
