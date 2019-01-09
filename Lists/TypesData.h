#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct ip
{
	unsigned char oneCell;//перва€ €чейка адресса
	unsigned char twoCell;//втора€ €чейка адресса
	unsigned char threeCell;//треть€ €чейка адресса
	unsigned char fourCell;//четвЄрта€ €чейка адресса
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
	struct ip _ip;//структура ip адресса, состоит из четырЄх переменных, кажда€ из которых отвечает за свою €чейку адресса
	char *name_pc;//название ѕ 
	char *name_user;//»м€ пользовател€
	char *surname_user;//‘амили€ пользовател€
	char *groupe_user;//Ќазвание группы
	struct TypePC typePC;//“ип ѕ 
};

struct DBAndTPC
{
	struct TypePC *typePC;
	struct db _db;
};
struct list
{
	struct db _db; // поле данных
	struct list *next; // указатель на следующий элемент
	struct list *prev; // указатель на предыдущий элемент
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
