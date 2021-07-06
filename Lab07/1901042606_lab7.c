#include <stdio.h>
#include <stdlib.h>
#define MAX 69999

/* Emre YILMAZ - 1901042606 - Gebze Technical University */

int check_palindrome(int array[50], int ct)
{
	int result = 1;
	if(array[0]==-1 || ct<1)
		return 1;
	else
	{
		if(array[0]==array[ct-1])
		{
			result = result * check_palindrome(array+1,ct-1);
			return 1;
		}
			
		else
		{
			return 0;
		}
	}
}

int search_element(int array[20], int input, int ct)
{
	int result = 1;

	if(ct==20)
		return 1;

	else
	{
		if(array[0]==input)
		{
			result = 0;
			result = result * search_element(array+1, input, ct+1);
		}

		else
		{
			result = result * search_element(array+1, input, ct+1);
		}
	}

	return result;


}

/* Part 3 is cancelled */
/*float cosx(float n, float x)
{
	float result = 0;
	if(n==MAX+1)
		return 1;
	else
	{
		result = (1-((x*x)/((2*n+(2*n-3))*(2*n+(2*n-2)))));
		result = result * cosx(n+1, x);
	}

	return result;
}*/


int main()
{
	/* Part 1 */

	int i;
	int input; /* The number that user entered */
	int ct = 0; /* Indicates that how many numbers there are in the array */
	int array[50];

	for(i=0;i<50;i++)
	{
		printf("Please enter your %2i. number of array (-1 for stop): ",i+1);
		scanf("%d",&input);
		if(input==-1)
		{
			array[i] = input;
			break;
		}
		else
		{
			array[i] = input;
			ct++;
		}
	}

	check_palindrome(array,ct);
	if(check_palindrome(array,ct))
	{
		printf("Your array is palindrome.\n\n");
	}

	else
	{
		printf("Your array is not palindrome.\n\n");
	}
	
	/* Part 2 */

	int array2[20]; /* random number array */
	int num; /* number that is generated as randomly, it will fill the array2 */
	int input2; /* inpt number that user will be entred */
	ct = 0; /* will be sent to function. Indicates what element of array we care currently */
	for(i=0;i<20;i++)
	{
		num = (rand()%(100+1));
		array2[i] = num;
		printf("Your num %d. of array is %d\n",i+1,array2[i]);
	}

	printf("Please enter your input: ");
	scanf("%d",&input2);

	if(search_element(array2,input2,ct))
		printf("No, your input is NOT in the array.\n");
	else
	{
		printf("Yes, your input is in the array.\n");
	}

	/* Part 3 is cancelled */

	//float x; /* x value in the formula */
	//int n = 1; /* n value in the formula */
	/*printf("Enter your x value: ");
	scanf("%f",&x);
	printf("Result of your calculation according to cos(n,x) formula is %f\n",cosx(n, x));*/

}
