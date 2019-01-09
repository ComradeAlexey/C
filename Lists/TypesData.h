#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct ip
{
	unsigned char oneCell;//������ ������ �������
	unsigned char twoCell;//������ ������ �������
	unsigned char threeCell;//������ ������ �������
	unsigned char fourCell;//�������� ������ �������
};
struct editIP
{
	int a;
	int isString;
};
struct addIP
{
	int a;
	int isString;
};
struct TypePC
{
	char nameType[10];
	int typeNum;
};

struct db
{
	struct ip _ip;//��������� ip �������, ������� �� ������ ����������, ������ �� ������� �������� �� ���� ������ �������
	char *name_pc;//�������� ��
	char *name_user;//��� ������������
	char *surname_user;//������� ������������
	char *groupe_user;//�������� ������
	struct TypePC typePC;//��� ��
};

struct DBAndTPC
{
	struct TypePC *typePC;
	struct db _db;
};
struct list
{
	struct db _db; // ���� ������
	struct list *next; // ��������� �� ��������� �������
	struct list *prev; // ��������� �� ���������� �������
};

struct ListAndTypePC
{
	struct list *list;
	struct TypePC *typePC;
};

char ChoiceYN(char *str);
struct db ChoiceType(int lenghtTPC, struct TypePC *typesPC, struct db _db);
struct TypePC *AddInListTypePC(int *lenghtTypesPC, struct TypePC *typesPC);
char* AddString(char *name, int lenghtString);
int AddIP(int numPart);
