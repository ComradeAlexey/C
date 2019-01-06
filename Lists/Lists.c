#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include"Menu.h"

int main()
{
	struct TypePC *typesPC = NULL;
	int lenghtTypesPC = 0;
	int lenghtLists = 0;
	system("chcp 1251");
	struct list *head = NULL/* "голова" листа*/;
	Menu(head,&lenghtTypesPC,&lenghtLists,typesPC);
	return 0;
}