#include"TypesData.h"
void PrintListTypePC(struct TypePC *typesPC,int *lenghtTypesPC)
{
	for (int i = 0; i < &lenghtTypesPC; i++)
	{
		printf("\n Номер элемента списка типов ПК %d содержимое %s", i, typesPC[i].nameType);
	}
}
void dbPrint(struct db _db)
{
	//вывод IP
	printf("IP = %d.%d.%d.%d \n", _db._ip.oneCell, _db._ip.twoCell, _db._ip.threeCell, _db._ip.fourCell);
	//вывод имени пользователя
	printf("Name User = ");
	for (int i = 0; i < 10; i++)
	{
		printf("%c", _db.name_user[i]);
	}
	//вывод фамилии пользователя
	printf("\nSurName User = ");
	for (int i = 0; i < 10; i++)
	{
		printf("%c", _db.surname_user[i]);
	}
	//
	printf("\nName PC = ");
	for (int i = 0; i < 10; i++)
	{
		printf("%c", _db.name_pc[i]);
	}

	printf("\nGroupe user = ");
	for (int i = 0; i < 5; i++)
	{
		printf("%c", _db.groupe_user[i]);
	}

	printf("\nType PC = %s", _db.typePC.nameType);

}

void listPrint(struct list *lst) {
	struct list *p;
	p = lst;
	while (p != NULL)
	{
		dbPrint(p->_db); // вывод значения элемента p
		if (p->next != NULL)
			p = p->next; // переход к следующему узлу
		else
			return;
	}
}