#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<string.h>

#define MAX_NAME 20
#define MAX_SIZE 100

typedef struct BookInfo {
	char name[MAX_NAME];
	int no;
	int price;
}BookInfo;

typedef struct BookList {
	BookInfo* bi;
	int length;
}BookList;

bool CreateList(BookList* ps);
bool AddList(BookInfo* ps);
void ShowList(BookInfo* ps, int length);
bool ModifyList(BookList* ps);
bool DeleteList(BookList* ps);