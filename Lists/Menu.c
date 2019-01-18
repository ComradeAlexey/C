#include <stdio.h>
#include"TypesData.h"
#include"AddList.h"
#include"DeleteList.h"
#include"EditList.h"
#include"SortList.h"
#include"Print.h"
#include"FileWork.h"
void Menu(struct list *head,int *lenghtTypesPC, int *lenghtLists,struct TypePC *typesPC)
{
	while (1)
	{
		system("cls");
		if (head == NULL)
		{
			printf("Введите нужный Вам пункт\n");
			printf("1)Добавить корневой элемент\n");
			printf("2)Выйти\nВведите число = ");
			int choice;
			scanf_s("%d", &choice);
			struct db _db;
			struct DBAndTPC _DBAndTPC;
			switch (choice)
			{
			case 1:  
				_DBAndTPC = dbEnterData(lenghtTypesPC, typesPC);
				typesPC = _DBAndTPC.typePC;
				_db = _DBAndTPC._db;
				head = init(_db, lenghtLists);
				break;
			case 2:
				return;
				break;
			}
		}
		else
		{
			printf("Введите нужный Вам пункт\n");
			printf("1)Добавить элемент между элементами\n");
			printf("2)Добавить элемент в конец списка\n");
			printf("3)Редактировать элемент\n");
			printf("4)Редактировать тип ПК\n");
			printf("5)Удалить элемент между элементами\n");
			printf("6)Удалить последний в списке элемент\n");
			printf("7)Удалить корневой элемент\n");
			printf("8)Удалить полностью весь список элементов\n");
			printf("9)Удалить тип ПК\n");
			printf("10)Удалить все типы ПК\n");
			printf("11)Вывести все элементы\n");
			printf("12)Сортировка по имени\n");
			printf("13)Сортировка по фамилии\n");
			printf("14)Сортировка по группе пользователя\n");
			printf("15)Сортировка по типу ПК\n");
			printf("16)Сортировка по имени ПК\n");
			printf("17)Сортировка по IP(в порядке возрастания суммы всех чисел в IP адресе)\n");
			printf("18)Вывод в файл\n");
			printf("19)Выйти\nВведите число = ");
			
			int choice;
			scanf_s("%d", &choice);
			struct ListAndTypePC LATPC;
			switch (choice)
			{
			case 1:

				LATPC = addelem(head, lenghtLists, lenghtTypesPC, typesPC);
				head = LATPC.list;
				typesPC = LATPC.typePC;
				if (*lenghtLists == 1)
					head = AllEditTPC(head,typesPC, *lenghtLists);
				break;
			case 2:
				LATPC = addElemToEnd(head, lenghtTypesPC, typesPC, lenghtLists);
				head = LATPC.list;
				typesPC = LATPC.typePC;
				if(*lenghtLists == 1)
					head = AllEditTPC(head, typesPC, *lenghtLists);
				break;
			case 3:
				EditElement(head, lenghtTypesPC, typesPC, *lenghtLists);
				break;
			case 4:
				EditTypePC(lenghtTypesPC, *lenghtLists, typesPC,head);
				break;
			case 5:
				DeletElemAfter(head,lenghtLists);
				break;
			case 6:
				DeleteEndElement(head, lenghtLists);
				break;
			case 7:
				head = DeleteHead(head, lenghtLists);
				break;
			case 8:
				free(head);
				head = NULL;
				*lenghtLists = 0;
				break;
			case 9:
				head = DeleteTypePC(head, typesPC, lenghtTypesPC,lenghtLists);
				break;
			case 10:
				/*typesPC = */DeleteAllTypesPC(typesPC, lenghtTypesPC);
				break;
			case 11:
				listPrint(head);
				break;
			case 12:
				head = AscendingSort(head, 1, lenghtLists);
				break;
			case 13:
				head = AscendingSort(head, 2, lenghtLists);
				break;
			case 14:
				head = AscendingSort(head, 3, lenghtLists);
				break;
			case 15:
				head = AscendingSort(head, 5, lenghtLists);
				break;
			case 16:
				head = AscendingSort(head, 4, lenghtLists);
				break;
			case 17:
				head = AscendingSort(head, 6, lenghtLists);
				break;
			case 18:
				WriteFile(head, *lenghtLists,typesPC, *lenghtTypesPC);
				break;
			case 19:
				return;
				break;
			}
		}
		printf("\n__________________________________________________________________\n");
		system("pause");
	}
}