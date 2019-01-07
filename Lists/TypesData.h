#pragma once
struct ip
{
	unsigned char oneCell;//перва€ €чейка адресса
	unsigned char twoCell;//втора€ €чейка адресса
	unsigned char threeCell;//треть€ €чейка адресса
	unsigned char fourCell;//четвЄрта€ €чейка адресса
};

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
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

struct list
{
	struct db _db; // поле данных
	struct list *next; // указатель на следующий элемент
	struct list *prev; // указатель на предыдущий элемент
};