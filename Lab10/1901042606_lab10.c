#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Emre YILMAZ - 1901042606 - Gebze Technical University */

typedef struct booKs
{
	char title[30];
	char author[30];
	char subject[30];
	int ident;
	int public;
}Book;


Book *allocate(Book *books, int ct) /* This function makes reallocation without realloc function. */
{
	int i;
	Book *books2;

	books2 = (Book*) calloc(ct,sizeof(Book));
	for(i=0;i<ct-1;i++) books2[i] = books[i];
	if(books!=NULL) free(books);
	books = books2;
	return books;
}

Book *add_book(Book *books, int ct) /* This function gets input from user to add a new entry */
{
	books = allocate(books,ct+1); /* reallocation */

	/* getting inputs */
	printf("Please enter book title = ");
	scanf("%s",books[ct].title);
	printf("Please enter book author = ");
	scanf("%s",books[ct].author);
	printf("Please enter book subject = ");
	scanf("%s",books[ct].subject);
	printf("Please enter publication year = ");
	scanf("%d",&books[ct].public);
	printf("Please enter ID of book = ");
	scanf("%d",&books[ct].ident);
	
	printf("\n****************************\n\n");

	return books;
}

void get_title(Book *books, int ct) /* this function gets title input from user and search it in book array, */
{									/* if it finds, it is gonna print it; if it does NOT find print error message */

	int i;
	int found_ct = 0; /* Indicates whether the book that user entered is found */ 
	char input[30]; /* Title input for user */
	printf("Enter a book title = ");
	scanf("%s",input);

	/* Searching and printing */
	for(i=0;i<ct;i++)
	{
		if(strcmp(books[i].title,input)==0)
		{
			printf("\nBook found.\nTitle => %s\nAuthor => %s\nSubject => %s\nYear => %d\nID => %d\n\n",books[i].title, books[i].author, books[i].subject, books[i].public, books[i].ident);
			found_ct++;
			printf("****************************\n");
		}
	}

	if(found_ct==0) /* if the subject is not found */
		printf("\nBook is not found.\n****************************\n");
}

void get_subject(Book *books, int ct) /* this function gets subject input from user and search it in book array, */
{									/* if it finds, it is gonna print it; if it does NOT find print error message */

	int i;
	int found_ct = 0; /* Indicates whether the book that user entered is found */ 
	char input[30]; /* Title input for user */
	printf("Enter a book subject = ");
	scanf("%s",input);

	/* Searching and printing */
	for(i=0;i<ct;i++)
	{
		if(strcmp(books[i].subject,input)==0)
		{
			printf("\nBook found.\nTitle => %s\nAuthor => %s\nSubject => %s\nYear => %d\nID => %d\n",books[i].title, books[i].author, books[i].subject, books[i].public, books[i].ident);
			found_ct++;
			printf("****************************\n\n");
		}
	}

	if(found_ct==0) /* if the subject is not found */
		printf("\nBook is not found.\n****************************\n");
}

void get_author(Book *books, int ct)/* this function gets subject input from user and search it in book array, */
{									/* if it finds, it is gonna print it; if it does NOT find print error message */

	int i;
	int found_ct = 0; /* Indicates whether the book that user entered is found */ 
	char input[30]; /* Title input for user */
	printf("Enter a book author = ");
	scanf("%s",input);

	/* Searching and printing */
	for(i=0;i<ct;i++)
	{
		if(strcmp(books[i].author,input)==0)
		{
			printf("\nBook found.\nTitle => %s\nAuthor => %s\nSubject => %s\nYear => %d\nID => %d\n",books[i].title, books[i].author, books[i].subject, books[i].public, books[i].ident);
			found_ct++;
			printf("****************************\n\n");
		}
	}

	if(found_ct==0) /* if the author is not found */
		printf("\nBook is not found.\n****************************\n");
}

void list_year(Book *books,int ct) /* this function sorts the array ascending order according to year  */
{
	Book *sort_year = NULL; /* a new temp array */
	Book temp; /* temporary struct variable */
	int i,k;
	int min_year;
	int min_index;

	/* memory allocation for new temp array */
	sort_year = (Book*)calloc(ct,sizeof(Book));

	/* copying books to temp array */
	for(i=0;i<ct;i++)
		sort_year[i] = books[i];

	/* sort the array ascending order */
	for(i=0;i<ct-1;i++)
	{
		min_index = i;
		min_year = sort_year[i].public;

		for(k=i+1;k<ct;k++)
		{
			if(sort_year[k].public<min_year)
			{
				min_index = k;
				min_year = sort_year[k].public;
			}
		}

		temp = sort_year[i];
		sort_year[i] = sort_year[min_index];
		sort_year[min_index] = temp; 
	}

	/* printing the sorted array */
	printf("\nList of Books\n****************************\n");
	for(i=0;i<ct;i++)
	{
		printf("%d. Book:\nTitle => %s\nAuthor => %s\nSubject => %s\nYear => %d\nID => %d\n",i+1,sort_year[i].title, sort_year[i].author, sort_year[i].subject, 
			sort_year[i].public, sort_year[i].ident);
		printf("****************************\n");
	}

	printf("\n\n");
	free(sort_year);
}

void list_id(Book *books,int ct) /* this function sorts the array ascending order according to id */
{
	Book *sort_id = NULL; /* a new temp array */
	Book temp; /* temporary struct variable */
	int i,k;
	int min_id;
	int min_index;

	/* memory allocation for new temp array */
	sort_id = (Book*)calloc(ct,sizeof(Book));

	/* copying books to temp array */
	for(i=0;i<ct;i++)
		sort_id[i] = books[i];

	/* sort the array ascending order */
	for(i=0;i<ct-1;i++)
	{
		min_index = i;
		min_id = sort_id[i].ident;

		for(k=i+1;k<ct;k++)
		{
			if(sort_id[k].ident<min_id)
			{
				min_index = k;
				min_id = sort_id[k].ident;
			}
		}

		temp = sort_id[i];
		sort_id[i] = sort_id[min_index];
		sort_id[min_index] = temp; 
	}

	/* printing the sorted array */
	printf("\nList of Books\n****************************\n");
	for(i=0;i<ct;i++)
	{
		printf("%d. Book:\nTitle => %s\nAuthor => %s\nSubject => %s\nYear => %d\nID => %d\n",i+1,sort_id[i].title, sort_id[i].author, sort_id[i].subject, 
			sort_id[i].public, sort_id[i].ident);
		printf("****************************\n");
	}
	printf("\n\n");
	free(sort_id);
}


int list_book(Book *books, int ct) /* menu choice 2, (list books choice) */
{
	int choose2;
	int flag=0; /* it indicates that the entry is valid or not */

	do
	{
		printf("\n****************************\n\nSUBMENU\n\t1. Get by Title\n\t2. Get by Author\n\t3. Get by Subject\n\t4. Sorted List by Year (DESC)\n\t5. List All Books\n\t6. EXIT SUBMENU\n\nChoose = ");
		scanf("%d",&choose2);

		/* if the entry is valid get a new entry */
		if(choose2<1 || choose2>6)
		{
			printf("Please enter a valid value.\n");
			continue;
		}

		else /* if the entry is ok, go on */
			flag=1;

		switch(choose2)
		{
			case 1:
				get_title(books,ct);
				break;
			case 2:
				get_author(books,ct);
				break;
			case 3:
				get_subject(books,ct);
				break;
			case 4:
				list_year(books,ct);
				break;
			case 5:
				list_id(books,ct);
				break;
			case 6:
				return 0;
				
		}
	}while(flag!=1);

	return 1;
}


int main()
{
	Book *books = NULL;
	int ct = 0;
	int choose1;
	int return_val;
	/* ------------------------------------------   Menu ------------------------------------------------------------*/
	do
	{
		printf("MENU\n\t1. Add New Book\n\t2. List Book\n\t3. Exit\n\nChoose = ");
		scanf("%d",&choose1);
		if(choose1<1 || choose1>3)
		{
			printf("\nPlease enter a valid entry.\n");
			continue;
		}

		switch(choose1)
		{
			case 1:
				books = add_book(books,ct);
				ct++;
				break;
			case 2:
				list_book(books,ct);
				break;
			case 3:
				printf("Bye.\n");
				return 1;
			default:
				continue;	
		}
		
	}while(1);
	
}
