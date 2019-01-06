#include"TypesData.h"
struct editIP EditIP(int numPart)
{
	struct editIP edit;
	int a = 0, isString = 0;
	a = 0;
	isString = 0;
	char str[3];
	printf("Введите %d часть IP = ", numPart);
	scanf_s("%4s", &str);
	fseek(stdin, 0, SEEK_END);
	for (int i = 0; i < 3; i++)
	{
		if (str[i] == '\0')
		{
			i = 3;
		}
		else if ((str[i] > '9' || str[i] < '0') & (str[i] != '\0'))
		{
			isString = 1;
		}
	}
	if (isString == 0)
	{
		if (str[1] == '\0')
		{
			a += str[0] - '0';
		}
		else if (str[2] == '\0')
		{
			a += ((str[0] - '0') * 10) + (str[1] - '0');
		}
		else
		{
			a += (((str[0] - '0') * 100) + ((str[1] - '0') * 10) + (str[2] - '0'));
		}
	}
	edit.a = a;
	edit.isString = isString;
	return edit;
}
void EditElement(struct list *head)
{
	struct list *cur = head;
	int lenght, i = 0;
	do
	{
		printf("Введите индекс редактируемого элемента(отчёт начинается с 0) = ");
		scanf_s("%d", &lenght);
	} while (lenght < 0);
	while ((i < lenght) & (cur->next != NULL))
	{
		cur = cur->next;
		i++;
	}
	if (i == lenght)
	{
		printf("выберите пункт который хотите редактировать\n");
		printf("1)IP\n");
		printf("2)Имя пользователя\n");
		printf("3)Фамилию пользователя\n");
		printf("4)Группу пользователя\n");
		printf("5)Имя ПК\n");
		printf("6)Тип ПК\n");
		printf("Введите число = ");
		int choice;
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Выберите часть IP которую хотите редактировать : 1,2,3,4\n");
			int choiceIP;
			do
			{
				scanf_s("%d", &choiceIP);
			} while (choiceIP < 1 || choiceIP >4);
			printf("Введите IP\n p.s. интервал значения от 0 до 255\n");
			struct editIP edit;
			switch (choiceIP)
			{
			case 1:
				do
				{
					edit = EditIP(1);
				} while (edit.a < 0 || edit.a > 255 || !edit.isString == 0);
				cur->_db._ip.oneCell = edit.a;
				break;
			case 2:
				do
				{
					edit = EditIP(2);
				} while (edit.a < 0 || edit.a > 255 || !edit.isString == 0);
				cur->_db._ip.twoCell = edit.a;
				break;
			case 3:
				do
				{
					edit = EditIP(3);
				} while (edit.a < 0 || edit.a > 255 || !edit.isString == 0);
				cur->_db._ip.threeCell = edit.a;
				break;
			case 4:
				do
				{
					edit = EditIP(4);
				} while (edit.a < 0 || edit.a > 255 || !edit.isString == 0);
				cur->_db._ip.fourCell = edit.a;
				break;
			}
			fseek(stdin, 0, SEEK_END);
			break;
		case 2:
			printf("Введите имя пользователя p.s. только a,b,c... и 1,2,3, остальные символы удаляются! = ");
			scanf_s("%10s", &cur->_db.name_user);
			ClearTrash(cur->_db.name_user, 10);
			fseek(stdin, 0, SEEK_END);
			break;
		case 3:
			printf("\nВведите фамилию пользователя p.s. only a,b,c... and 1,2,3 other symbols delete!  = ");
			scanf_s("%10s", &cur->_db.surname_user);
			ClearTrash(cur->_db.surname_user, 10);
			fseek(stdin, 0, SEEK_END);
			break;
		case 4:
			printf("\nВведите группу пользователя пользователя p.s. only a,b,c... and 1,2,3 other symbols delete!  = ");

			scanf_s("%5s", &cur->_db.groupe_user);
			fseek(stdin, 0, SEEK_END);
			ClearTrash(cur->_db.groupe_user, 5);
			break;
		case 5:
			printf("\nВведите имя ПК p.s. only a,b,c... and 1,2,3 other symbols delete!  = ");
			scanf_s("%10s", &cur->_db.name_pc);
			fseek(stdin, 0, SEEK_END);
			ClearTrash(cur->_db.name_pc, 10);
			break;
			/*case 6:

			do
			{
			printf("\nВведите имя пользователя \n p.s. 0 -> one type, 1 -> two type, 2 -> three type \n = ");
			scanf_s("%d", &type);
			} while (!(type == 1 || type == 2 || type == 0));
			fseek(stdin, 0, SEEK_END);
			break;*/
		}
	}
	else {
		printf("Данного элемента нету в списке!!!\n");
	}
}