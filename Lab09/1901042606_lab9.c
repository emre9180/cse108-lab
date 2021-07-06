#include <stdio.h>
#include <string.h> /* For 3rd part */

/* Emre YILMAZ - 1901042606 - Gebze Technical University */

typedef struct Lines
{
	double x1,y1,x2,y2,x3,y3;
	double m; /* slope */
}Line;

typedef struct Grades
{
	float midterm,final,homework;
}grades;

typedef struct Students
{	
	char name[30];
	int id;
	grades grade;

}students;

typedef struct Games
{
	char name[30]; /* name of the game */
	char platform[30][30]; /* platforms */
	float score;
}games;


void Part1()
{
	Line Struct_line;

	/* Getting inputs from user */
	printf("Please enter x1: ");
	scanf("%lf",&Struct_line.x1);
	printf("Please enter y1: ");
	scanf("%lf",&Struct_line.y1);
	printf("Please enter x2: ");
	scanf("%lf",&Struct_line.x2);
	printf("Please enter y2: ");
	scanf("%lf",&Struct_line.y2);
	printf("Please enter x3: ");
	scanf("%lf",&Struct_line.x3);

	/* Slope formula => y2-y1 / x2-x1 */
	Struct_line.m = (Struct_line.y2-Struct_line.y1) / (Struct_line.x2 - Struct_line.x1);

	/* Egimi ve 1 noktasi bilinen dogru denklemi => y-y1=m.(x-x1) */

	Struct_line.y3 = (Struct_line.m*(Struct_line.x3-Struct_line.x1)) + Struct_line.y1;

	printf("y3 value is: %lf\nSlope is: %lf",Struct_line.y3,Struct_line.m);
}

void Part2()
{
	printf("\n\n----------------------------------------------------------------------- PART 2 -----------------------------------------------------------------------------");
	students arr[100]; /* Array that keeps the students */
	grades averages;

	int stud_num; /* Indicates student number. Will be got from user */
	int i; /* Loop */
	int flag = -1; /* Indicates that whether there are student that has the id that user entered */
	int id; /* ID input from user to find student */

	/* Sum of miterm, final and homwork grades. Will be used to calculate averages. */
	double sum_mid = 0; /* sum of midterm */
	double sum_fin = 0; /* sum of final */
	double sum_hom = 0; /* sum of homework */

	printf("\n\nHow many students do you have?: ");
	scanf("%d",&stud_num);


	for(i=0;i<stud_num;i++)
	{
		printf("\nEnter name of student: ");
		scanf(" %[^\n]s",arr[i].name);
		printf("Enter the id: ");
		scanf("%d",&arr[i].id);
		printf("Enter the midterm grade: ");
		scanf("%f",&arr[i].grade.midterm);
		printf("Enter the final grade: ");
		scanf("%f",&arr[i].grade.final);
		printf("Enter the homework grade: ");
		scanf("%f",&arr[i].grade.homework);

		/* Adding grades to sum variables */
		sum_mid += arr[i].grade.midterm;
		sum_fin += arr[i].grade.final;
		sum_hom += arr[i].grade.homework;
	}

	/* Calculating and assigning averages */
	averages.midterm = sum_mid/stud_num;
	averages.final = sum_fin/stud_num;
	averages.homework = sum_hom/stud_num;

	/*Printing averages */
	printf("\nAverage of midterm: %f\nAverage of final: %f\nAverage of homwork: %f",averages.midterm, averages.final, averages.homework);


	/* ID Finder -> */
	/*Getting ID input */
	printf("\n\nWhich student do you want to see, please enter id: ");
	scanf("%d",&id);

	/* Searching he id */
	for(i=0;i<stud_num;i++)
	{
		if(arr[i].id==id)
		{
			printf("\nYour student is: %s\nID: %d\nMidterm,Final and Homework grades: %f %f %f",arr[i].name,arr[i].id,arr[i].grade.midterm,arr[i].grade.final,arr[i].grade.homework);
			flag = 1; /* If we find, make the flag 1 */
			break;
		}
	}

	/* If there is no student that has the id user entered */
	if(flag==-1) 
		printf("\nThere are no student that has ID %d",id);

}

int search_insert(char platforms[30][30],char platform[30], int ct)
{
	int i;
	int flag = 0;

	for(i=0;i<ct;i++)
	{
		if(strcmp(platforms[i],platform)==0)
		{
			flag = 1;
			break;
		}
	}

	if(flag==0)
		strcpy(platforms[ct],platform);

	return flag;
}

void search_print(char platform[30], games gamesa[100], int ct_games)
{
	int i,k;

	for(i=0;i<ct_games;i++)
	{
		for(k=0;k<30;k++)
		{
			if(strcmp(platform,gamesa[i].platform[k])==0)
				printf("%s - ",gamesa[i].name);
		}
	}
	printf("\n\n");
}


void Part3()
{
	printf("\n\n---------------------------------------------------------------------------------- PART 3 -----------------------------------------------------------------------------");
	int i,k;
	int game_num; /* Total game number, will be decided by the user */
	int genre_num; /* Total platform number, will be decided by the user */
	games gamesa[100]; /* array that keeps all games */
	char platforms[30][30]; /* array that keeps all platforms */
	int platform_ct = 0; /* indicates how many platforms we have */
	double sum_score = 0; /* sum of scores of games */

	printf("\n\nHow many games do you have?: ");
	scanf("%d",&game_num);

	for(i=0;i<game_num;i++)
	{
		/* getting name input */
		printf("\nEnter the name of game: ");
		scanf(" %[^\n]s",gamesa[i].name);

		/* getting platform input */
		printf("How many platforms does your game has?: ");
		scanf("%d",&genre_num);
		for(k=0;k<genre_num;k++)
		{
			printf("Enter your %d. platform: ",k+1);
			scanf("%s",gamesa[i].platform[k]);

			if(!search_insert(platforms,gamesa[i].platform[k],platform_ct)) /* If the platform that user has just entered is in the platform array, do nothing. If is not, insert to platform array and 
																		increase the platform counter by 1 */
				platform_ct++;
		}

		/*getting score input */
		printf("Enter your score: ");
		scanf("%f",&gamesa[i].score);
		sum_score += gamesa[i].score; /* add the score to sum variable */
	}

	/* calculate and print the average of scores */
	printf("\nAverage of the scores of the games is: %f",sum_score/game_num);

	/* search and print the games that its platform matches the variable in platform list */
	for(i=0;i<platform_ct;i++)
	{
		printf("\n\n%s games: ",platforms[i]);
		search_print(platforms[i],gamesa,game_num); /* print all games of 1 platform */
	}

}

int main()
{
	Part1();
	Part2();
	Part3();
}










