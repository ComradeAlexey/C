#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include"TypesData.h"
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
		printf("\n%d) %s", i, typesPC[i]);
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