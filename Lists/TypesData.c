#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include"TypesData.h"
void ChoiceYN(char *str, char *choice)
{
	*choice = ' ';
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