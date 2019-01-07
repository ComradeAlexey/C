#include"TypesData.h"
struct editIP EditIP(int numPart)
{
	struct editIP edit;
	int a = 0, isString = 0;
	a = 0;
	isString = 0;
	char str[3];
	printf("������� %d ����� IP = ", numPart);
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

void ChoiceYN(char *str, char *choice)
{
	int b;
	do
	{
		printf("\n%s? ���� �� �� ������� Y(y), ����� N(n) = ", str);
		scanf_s("%c", choice);
		fseek(stdin, 0, SEEK_END);
		switch (*choice)
		{
		case 'N':
			b = 1;
			break;
		case 'n':
			b = 1;
			break;
		case 'y':
			b = 1;
			break;
		case 'Y':
			b = 1;
			break;
		default:
			b = 0;
			break;
		}
	} while (b == 0);
}
struct db ChoiceType(int lenghtTPC, struct TypePC *typesPC, struct db _db)
{
	int choIce = -1;
	printf("\n�������� ��� �� �� ������ � ������� ���������� ����� ���� �����:");
	for (int i = 0; i < lenghtTPC; i++)
	{
		printf("\n%d) %s", i, typesPC[i]);
	}
	do
	{
		printf("\n������� ���������� ����� �� 0 �� %d = ", lenghtTPC - 1);
		scanf_s("%d", &choIce);
	} while (choIce < 0 || choIce >= lenghtTPC);
	_db.typePC = typesPC[choIce];
	return _db;
}

struct TypePC *AddInListTypePC(int *lenghtTypesPC, struct TypePC *typesPC)
{
	int i = *lenghtTypesPC;
	i++;
	typesPC = (struct  TypePC*)realloc(typesPC, i * sizeof(struct TypePC));
	printf("������� �������� ���� �� = ");
	typesPC[i - 1].typeNum = i;
	scanf_s("%s", typesPC[i - 1].nameType, 10);
	*lenghtTypesPC = i;
	return typesPC;
}

void EditElement(struct list *head, int *lenghtTypesPC, struct TypePC *typesPC)
{
	struct list *cur = head;
	int lenght, i = 0;
	int lenghtTPC = *lenghtTypesPC;//������ ��������� lenghtTypesPC
	do
	{
		printf("������� ������ �������������� ��������(����� ���������� � 0) = ");
		scanf_s("%d", &lenght);
	} while (lenght < 0);
	while ((i < lenght) & (cur->next != NULL))
	{
		cur = cur->next;
		i++;
	}
	if (i == lenght)
	{
		printf("�������� ����� ������� ������ �������������\n");
		printf("1)IP\n");
		printf("2)��� ������������\n");
		printf("3)������� ������������\n");
		printf("4)������ ������������\n");
		printf("5)��� ��\n");
		printf("6)��� ��\n");
		printf("������� ����� = ");
		int choice;
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("�������� ����� IP ������� ������ ������������� : 1,2,3,4\n");
			int choiceIP;
			do
			{
				scanf_s("%d", &choiceIP);
			} while (choiceIP < 1 || choiceIP >4);
			printf("������� IP\n p.s. �������� �������� �� 0 �� 255\n");
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
			ChoiceYN("������ �� �� �������� ����� ��� ��", &choice);
			if (choice == 'y' || choice == 'Y')
			{
				typesPC = AddInListTypePC(lenghtTypesPC, typesPC);
				lenghtTPC = *lenghtTypesPC;
				ChoiceYN("������ �� �� �������� ����� ��� �� � �������� ���� ������� �� ��� ������� ������ ���", &choice);
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
		printf("������� �������� ���� � ������!!!\n");
	}
}