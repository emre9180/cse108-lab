#include <stdio.h>

/* Emre YILMAZ - 1901042606 - Gebze Technical University */

double average_finder(int x, int y, int array[][y])
{
	double sum = 0; /* sum of even indices */
	int i,j; /*loop*/
	int even_ct = 0; /* keeps the number of even indices */

	/* Sum find */
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			if((i+j)%2 == 0)
			{
				sum += array[i][j];
				even_ct++;
			}
		}
	}

	/* calculate average */
	double result = (sum /(even_ct));
	return result;
}

void fill_array(int x, int y, int array[][y])
{	
	int i,j; /* loop */
	int ct = 1; /* start 1 from as told in PDF */
	/* Filling the array according to rule */
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			array[i][j] = ((2*(ct*ct)) - 3);
			//printf("%d\n",ct);
			ct++;
		}

	}
}

void intervew(char* s1, char* s2, char *s3)
{
	int ct1 = 0, ct2 = 0; /* which char do we care */
	int ct = 0; /* which char do we write */

	while(1)
	{
		if(s1[ct1]!='\0')
		{
			s3[ct]=s1[ct1];
			ct1++;
			ct++;
		}

		if(s2[ct2]!='\0')
		{
			s3[ct] = s2[ct2];
			ct2++;
			ct++;
		}

		if(s1[ct1]=='\0' && s2[ct2]=='\0')
			return;

	}
	
}

int main()
{
	int i,j;
	/* matrixs that will be filled and calculated average */
	int array1[4][9];
	int array2[3][5];
	int array3[2][3];
	/* fill the matrix */
	fill_array(4,9,array1);
	fill_array(3,5,array2);
	fill_array(2,3,array3);

	/* print the matrix */
	printf("MATRIX-1\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<9;j++)
			printf("%-10d ",array1[i][j]);
		printf("\n");
	}

	/* print the average of matrix */
	printf("\nAverage of matrix: %.1lf\n\n",average_finder(4,9,array1));

	/* print the matrix */
	printf("MATRIX-2\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
			printf("%-10d ",array2[i][j]);
		printf("\n");
	}

	/* print the average of matrix */
	printf("\n\nAverage of matrix: %.1lf\n\n",average_finder(3,5,array2));

	/* EXAMPLE IN THE PDF */
	/*for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
			printf("%-10d ",array3[i][j]);
		printf("\n");
	}

	printf("\n\nAverage of array: %.1lf\n\n",average_finder(2,3,array3));*/


	char str1[20];
	char str2[20];
	printf("\n\nEnter your first string: ");
	scanf("%s",str1);
	printf("Enter your second string: ");
	scanf("%s",str2);
	char str3[40]; /* result string */
	intervew(str1,str2,str3);
	printf("\n\nNew string -> %s",str3);

	
	





}
