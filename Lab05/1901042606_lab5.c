#include <stdio.h>
#include <stdlib.h>

/* Emre YILMAZ - 1901042606 - Gebze Technical University */


void expression0 (int x, int *result)
{
	/* Do the calculation and assign */
	*result = (x*x) + 5;
}

void expression1 (int x, int *result)
{
	/* Do the calculation and assign */
	*result = (2*x) + 1;
}

void expression2 (int x, int *result)
{
	/* Do the calculation and assign */
	*result = (x*x);
}


void addition (void (*func) (int ,int*), int *sum,int n)
{
	int i;
	int result;

	/* Getting summation of calculations of expressionN */
	for(i=0;i<=n;i++)
	{
		func(i,&result);
		*sum += result;
	}


}

void calculation (int *sumArray , int n)
{
	int sum = 0;

	/* Get the summation and assign to array */ 
	addition(expression0, &sum, n);
	sumArray[0] = sum;
	sum = 0;

	/* Get the summation and assign to array */ 
	addition(expression1, &sum, n);
	sumArray[1] = sum;
	sum = 0;

	/* Get the summation and assign to array */ 
	addition(expression2, &sum, n);
	sumArray[2] = sum;

} 


void createArray(int (*array)[10])
{
	int randomNumber;

	int i,j;

	for(i=0;i<10;i++) /* filling the array */
	{
		for(j=0;j<10;j++)
		{
			randomNumber = rand () %90 + 10; /* getting random number and assigning it */
			array[i][j] = randomNumber;
		}
	}
}

void game()
{
	int i,j; /* for loops */
	int array[10][10];
	createArray(array); /* creation of 2D array */

	for(i=0;i<10;i++) /* printing the 2D array */
	{
		for(j=0;j<10;j++)
		{
			printf("%d ",array[i][j]);
		}

		printf("\n");
	}
	printf("\n\n");


	/* game starts */

	int choice_i;
	int choice_j;

	while(1)
	{	
		/* Getting input from user */
		printf("Which element of the matrix do you want to reach?\ni: ");
		scanf("%d",&choice_i);
		printf("j: ");
		scanf("%d",&choice_j);

		if(choice_j<0 || choice_i<0 || choice_i>9 || choice_j>9) /* If the input is invalid, terminate the program */
		{
			printf("Invalid input. Terminating...\n");
			break;
		}

		printf("%d. row %d. column of the matrix is %d\n\n",choice_i,choice_j,array[choice_i][choice_j]); /* If the input valid, print the result */

	}

}


int main()
{
	/* Part1 */

	int N; /* bound */
	int i; /* LOOP */
	int array[3]; 

	/* Getting the bound from user */
	printf("Please enter N value: ");
	scanf("%d",&N);

	/* Call the function and doing the calculations and assigning process*/
	calculation(array,N);

	/* Printing result array */
	for(i=0;i<3;i++)
	{
		printf("Sum of expression%d: %d\n",i,array[i]);
	}
	printf("\n\n");

	/* Part2 */
	game(); 

	
}
