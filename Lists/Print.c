#include"TypesData.h"
void PrintListTypePC(struct TypePC *typesPC,int *lenghtTypesPC)
{
	for (int i = 0; i < *lenghtTypesPC; i++)
	{
		printf("\n ����� �������� ������ ����� �� %d ���������� %s", i, typesPC[i].nameType);
	}
}
void dbPrint(struct db _db)
{
	//����� IP
	printf("\nIP = %d.%d.%d.%d \n", _db._ip.oneCell, _db._ip.twoCell, _db._ip.threeCell, _db._ip.fourCell);
	//����� ����� ������������
	printf("Name User = ");
	for (int i = 0; i < 10; i++)
	{
		printf("%c", _db.name_user[i]);
	}
	//����� ������� ������������
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
		dbPrint(p->_db); // ����� �������� �������� p
		if (p->next != NULL)
			p = p->next; // ������� � ���������� ����
		else
			return;
	}
}