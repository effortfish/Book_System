#include"Book_Sys.h"

bool CreateList(BookList* ps)
{
	ps->bi = (BookInfo*)malloc(sizeof(BookInfo) * MAX_SIZE);
	if (!ps->bi)
	{
		printf("Fail\n");
		return false;
	}
	ps->length = 0;
	return true;
}

bool AddList(BookInfo* ps) 
{
	printf("Please enter the name of the book\n");
	scanf("%s", ps->name);
	printf("Please enter the no of the book\n");
	scanf("%d", &ps->no);
	printf("Please enter the price of the book\n");
	scanf("%d", &ps->price);
}

void ShowList(BookInfo* ps, int length)
{
	if (length > 0)
	{
		printf("Name: %s        No: %d             Price: %d\n\n", ps->name, ps->no, ps->price);
	}
	else if(length == 0)
	{
		printf("The list is empty.\n\n");
	}
}

bool ModifyList(BookList* ps)
{
	char M_name[MAX_NAME];
	char N_name[MAX_NAME];
	int N_no;
	int N_price;
	int choice;
	printf("Please enter the title of the book you want to modify\n");
	scanf("%s", M_name);
	for (int i = 0; i < ps->length; i++)
	{
		if (strcmp(M_name, ps->bi[i].name) == 0)
		{
			printf("Please enter the section you want to modify\n");
			printf("1.name        2.no         3.price\n");
			scanf("%d", &choice);
			switch (choice)
			{
			case 1:
				printf("Please enter a new name\n");
				scanf("%s", N_name);
				strcpy(ps->bi[i].name, N_name);
				printf("The modification was successful\n");
				break;
			case 2:
				printf("Please enter a new no\n");
				scanf("%d", &N_no);
				ps->bi[i].no = N_no;
				printf("The modification was successful\n");
				break;
			case 3:
				printf("Please enter a new price\n");
				scanf("%d", &N_price);
				ps->bi[i].price = N_price;
				printf("The modification was successful\n");
				break;
			}
			return true;
		}
	}
	printf("The specified book title could not be found\n");
	return false;
}

bool DeleteList(BookList* ps)
{
	char D_name[MAX_NAME];
	printf("Please enter the title of the book you want to delete\n");
	scanf("%s", D_name);
	if (ps->length == 1)
	{
		free(ps->bi);
		CreateList(ps);
		printf("The deletion was successful\n");
		return true;
	}
	for (int i = 0; i < ps->length; i++)
	{
		if (strcmp(D_name, ps->bi[i].name) == 0)
		{
			for (int j = i + 1; j < ps->length; j++)
			{
				ps->bi[i] = ps->bi[j];
				i++;
			}
			ps->length--;
			printf("The deletion was successful\n");
			return true;
		}
	}
	printf("The specified book title could not be found\n");
	return false;
}