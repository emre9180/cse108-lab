#include <stdio.h>

/* Emre YILMAZ - 1901042606 - Gebze Technical University */

int find_max_distance(int num_input)
{
	int i; /* used in loops */
	int new_input; /* it will represent the last number received from the user */
	int old_input; /* it will represent the previous number received from the user */
	int max_distance;

	for(i=0;i<num_input;i++) /* get inputs and calculate max distance */
	{
		printf("Enter your %d. number: ",i+1);
		scanf("%d",&new_input);

		if (i==0) /* if we are getting first input, max distance must be 0, since we have nothing to compare */
		{
			old_input = new_input;
			max_distance = 0;
		}

		else /* if we are NOT getting first input >> */
		{
			if((new_input - old_input) < 0 ) /* if the previous number is greater than the last number */
			{

				if (((new_input-old_input) * -1) > max_distance)
				{
					max_distance = (new_input-old_input) * -1;				
				}

			}

			else /* if the last number is greater than the previous number */
			{
				if ((new_input-old_input) > max_distance)
				{
					max_distance = (new_input-old_input);
				}
		
			}

			old_input = new_input; 
		}



	}

	return max_distance;
}

void input_output_max_distance()
{
	int num_input; /* input number */
	int max_distance; /* max_distance of two consecutive user entered numbers */

	printf("FUNCTION 2 -> -> ->\n\n");

	printf("How many number do you want to print? >> ");
	scanf("%d",&num_input);

	max_distance = find_max_distance(num_input);
	printf("Max distance between two consecutive numbers is: %d",max_distance);

}

void find_odd_average()
{

	int number; /* number that user enters */
	float sum = 0; /* sum of odd numbers user entered */
	float average = 0; /* average of odd numbers user entered */
	int ct = 0; /* number of odd numbers user entered */

	printf("FUNCTION 1 -> -> ->\n\n");

	while(1)
	{
		printf("Please enter positive numbers (end -1 to stop)\n");
		scanf("%d",&number);

		if(number==-1) /* if the number that user entered is -1, we must stop the getting input */ 
			break;

		else if (number<0) /* if the number that user entered is negative, we must stop the getting input */
		{
			printf("Please enter POSITIVE numbers!\n");
			continue;
		}

		else
		{
			if(number%2 == 1) /* if the number is positive and odd number, we must add it to sum */
			{
				sum += number;
				ct++;
			}
		}
	}

	average = sum/ct;
	printf("Average off odd numbers is: %f\n\n",average);
	
}



int main()
{
	find_odd_average();
	input_output_max_distance();
}
