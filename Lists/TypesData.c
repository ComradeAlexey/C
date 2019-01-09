#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include"TypesData.h"
#include"ClearTrash.h"
char  ChoiceYN(char *str)
{
	char choice[2];
	int b;
	do
	{
		printf("\n%s? Если да то введите Y(y), иначе N(n) = ", str);
		scanf_s("%s", choice,2);
		fseek(stdin, 0, SEEK_END);
		switch (choice[0])
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
	return choice[0];
}

struct db ChoiceType(int lenghtTPC, struct TypePC *typesPC, struct db _db)
{
	int choIce = -1;
	printf("\nВыберите тип ПК из списка и введите порядковый номер типа далее:");
	for (int i = 0; i < lenghtTPC; i++)
	{
		printf("\n%d) %s", i, typesPC[i].nameType);
	}
	do
	{
		printf("\nВведите порядковый номер от 0 до %d = ", lenghtTPC - 1);
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
	printf("Вводите название типа ПК = ");
	typesPC[i - 1].typeNum = i;
	scanf_s("%s", typesPC[i - 1].nameType, 10);
	*lenghtTypesPC = i;
	return typesPC;
}

struct addIP AddPartIP(int numPart)
{
	struct addIP add;
	int a = 0, isString = 0;
	a = 0;
	isString = 0;
	char str[4];
	printf("Введите %d часть IP = ", numPart);
	scanf_s("%s", &str, 4);
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
	add.a = a;
	add.isString = isString;
	return add;
}

int AddIP(int numPart)
{
	int ip;
	struct addIP add;
	do
	{
		add = AddPartIP(numPart);
	} while (add.a < 0 || add.a > 255 || !add.isString == 0);
	ip = add.a;

	return ip;
}

char* AddString(char *name, int lenghtString)
{
	char *str;
	str = (char *)malloc(lenghtString * sizeof(char));
	printf("Enter %s p.s. only a,b,c... and 1,2,3 other symbols delete! = ", name);
	scanf_s("%s", str, lenghtString + 1);
	ClearTrash(str, lenghtString);
	fseek(stdin, 0, SEEK_END);
	return str;
}