#include"Book_Sys.h"

void menu()
{
	printf("\n");
	printf("******************* Welcome! *******************\n");
	printf("1.Create List             "); printf("2.Add book\n");
	printf("3.Modify book             "); printf("4.Delete book\n");
	printf("5.Show                    "); printf("6.Exit\n");
	printf("************************************************\n");
}

int main()
{
	int choice, quantity;
	BookList bl;
	CreateList(&bl);
	while (1)
	{
		menu();
		printf("Please select function!\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			if (CreateList(&bl))
				printf("Created successfully\n\n");
			else
				printf("Creation failed\n");
			break;
		case 2:
			printf("Please enter the quantity you want to add\n");
			scanf("%d", &quantity);
			for (int i = 0; i < quantity; i++)
			{
				printf("NO.%d\n", i + 1);
				AddList(&bl.bi[i]);
			}
			bl.length = quantity;
			printf("The addition succeeded\n");
			break;
		case 3:
			ModifyList(&bl);
			break;
		case 4:
			DeleteList(&bl);
			break;
		case 5:
			printf("\n");
			printf("************Information*************\n\n");
			for (int i = 0; i < bl.length; i++)
			{
				ShowList(&bl.bi[i], bl.length);
			}
			printf("\n");
			printf("*************************************\n");
			break;
		case 6:
			break;
		}
		if (choice == 6)
			break;
	}
	return 0;
}