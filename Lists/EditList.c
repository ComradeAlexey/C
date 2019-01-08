#include"TypesData.h"
struct editIP EditIP(int numPart)
{
	struct editIP edit;
	int a = 0, isString = 0;
	a = 0;
	isString = 0;
	char str[3];
	printf("Введите %d часть IP = ", numPart);
	scanf_s("%s", &str,4);
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

int DoWhileEIP(int numPart)
{
	struct editIP edit;
	do
	{
		edit = EditIP(numPart);
	} while (edit.a < 0 || edit.a > 255 || !edit.isString == 0);
	return edit.a;
}

char* EditString(char *name, int lenghtString)
{
	char *str;
	str = (char *)malloc(lenghtString * sizeof(char));
	printf("Enter %s p.s. only a,b,c... and 1,2,3 other symbols delete! = ", name);
	scanf_s("%s", str, lenghtString);
	ClearTrash(str, lenghtString);
	fseek(stdin, 0, SEEK_END);
	return str;
}

void EditElement(struct list *head, int *lenghtTypesPC, struct TypePC *typesPC)
{
	struct list *cur = head;
	int lenght, i = 0;
	int lenghtTPC = *lenghtTypesPC;//данные указателя lenghtTypesPC
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
				cur->_db._ip.oneCell = DoWhileEIP(1);
				break;
			case 2:
				cur->_db._ip.twoCell = DoWhileEIP(2);
				break;
			case 3:
				cur->_db._ip.threeCell = DoWhileEIP(3);
				break;
			case 4:
				cur->_db._ip.fourCell = DoWhileEIP(4);
				break;
			}
			fseek(stdin, 0, SEEK_END);
			break;
		case 2:
			cur->_db.name_user = AddString("Name User", 10);
			break;
		case 3:
			cur->_db.surname_user = AddString("SurName User", 10);
			break;
		case 4:
			cur->_db.groupe_user = AddString("Groupe user", 5);
			break;
		case 5:
			cur->_db.name_pc = AddString("Name PC", 10);
			break;
		case 6:
		{
			char choice = '0';
			int b = 0;
			ChoiceYN("Хотите ли Вы добавить новый тип ПК", &choice);
			if (choice == 'y' || choice == 'Y')
			{
				typesPC = AddInListTypePC(lenghtTypesPC, typesPC);
				lenghtTPC = *lenghtTypesPC;
				ChoiceYN("Хотите ли Вы добавить новый тип ПК в качестве типа данного ПК или выбрать другой тип", &choice);
				if (choice == 'y' || choice == 'Y')
				{
					cur->_db.typePC = typesPC[lenghtTPC - 1];
				}
				else
				{
					cur->_db = ChoiceType(lenghtTPC, typesPC, cur->_db);
				}
			}
			else
			{
				cur->_db = ChoiceType(lenghtTPC, typesPC, cur->_db);
			}
		}
		break;
		}
	}
	else {
		printf("Данного элемента нету в списке!!!\n");
	}
}