#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct TypePC *typesPC = NULL;
int lenghtTypesPC = 0;
int lenghtLists = 0;
struct ip
{
	unsigned char oneCell;//������ ������ �������
	unsigned char twoCell;//������ ������ �������
	unsigned char threeCell;//������ ������ �������
	unsigned char fourCell;//�������� ������ �������
};

struct TypePC
{
	char nameType[10];
	int typeNum;
};

struct db
{
	struct ip _ip;//��������� ip �������, ������� �� ������ ����������, ������ �� ������� �������� �� ���� ������ �������
	char name_pc[10];//�������� ��
	char name_user[10];//��� ������������
	char surname_user[10];//������� ������������
	char groupe_user[5];//�������� ������
	struct TypePC typePC;//��� ��
};

struct list
{
	struct db _db; // ���� ������
	struct list *next; // ��������� �� ��������� �������
	struct list *prev; // ��������� �� ���������� �������
};

struct list * init(struct db a)  // � - �������� ������� ����
{
	struct list *lst;
	// ��������� ������ ��� ������ ������
	lst = (struct list*)malloc(sizeof(struct list));
	//���������� ������
	lst->_db = a;
	lst->next = NULL; // ��������� �� ��������� ����
	lst->prev = NULL; // ��������� �� ���������� ����
	lenghtLists++;
	return(lst);
}

void AddInListTypePC()
{
	
	typesPC = (struct  TypePC*)realloc(typesPC, lenghtTypesPC * sizeof(struct  TypePC));

	printf("������� �������� ���� �� = ");
	typesPC[lenghtTypesPC].typeNum = lenghtTypesPC;
	lenghtTypesPC++;
	scanf("%s", typesPC[lenghtTypesPC - 1].nameType);
}

void PrintListTypePC()
{
	for (int i = 0; i < lenghtTypesPC; i++)
	{
		printf("\n ����� �������� ������ ����� �� %d ���������� %s", i, typesPC[i].nameType);
	}
}
char ClearTrashSymbol(char c)
{
	int isTrash = 0;

	for (char i = 'a'; i <= 'z'; i++)
	{
		if (c == i)
			isTrash++;
	}
	for (char i = 'A'; i <= 'Z'; i++)
	{
		if (c == i)
			isTrash++;
	}
	for (char i = '0'; i <= '9'; i++)
	{
		if (c == i)
			isTrash++;
	}
	if (isTrash > 0)
		return c;
	else return ' ';
}

void ClearTrash(char* str, int lenght)
{
	for (int i = 0; i < lenght; i++)
	{
		str[i] = ClearTrashSymbol(str[i]);
	}
}

struct db dbEnterData()
{
	struct db _db;
	//���� IP
	printf("Enter of IP\n p.s. interval from 0 to 255\n");
	int a = 0, isString = 0, isNull1, isNull2;
	do
	{
		a = 0;
		isString = 0;
		char str[3];
		printf("Enter 1 part IP = ");
		scanf("%3s", &str);
		fseek(stdin, 0, SEEK_END);
		for (int i = 0; i < 3; i++)
		{

			if (str[i] == '\0')
			{
				i = 3;
			}
			else if (str[i] > '9' || str[i] < '0' & str[i] != '\0')
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

		_db._ip.oneCell = a;
	} while (a < 0 || a > 255 || !isString == 0);

	do
	{
		a = 0;
		isString = 0;
		char str[3];
		printf("Enter 2 part IP = ");
		scanf("%3s", &str);
		fseek(stdin, 0, SEEK_END);
		for (int i = 0; i < 3; i++)
		{

			if (str[i] == '\0')
			{
				i = 3;
			}
			else if (str[i] > '9' || str[i] < '0' & str[i] != '\0')
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

		_db._ip.twoCell = a;
	} while (a < 0 || a > 255 || !isString == 0);
	do
	{
		a = 0;
		isString = 0;
		char str[3];
		printf("Enter 3 part IP = ");
		scanf("%3s", &str);
		fseek(stdin, 0, SEEK_END);
		for (int i = 0; i < 3; i++)
		{

			if (str[i] == '\0')
			{
				i = 3;
			}
			else if (str[i] > '9' || str[i] < '0' & str[i] != '\0')
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

		_db._ip.threeCell = a;
	} while (a < 0 || a > 255 || !isString == 0);

	do
	{
		a = 0;
		isString = 0;
		char str[3];
		printf("Enter 4 part IP = ");
		scanf("%3s", &str);
		fseek(stdin, 0, SEEK_END);
		for (int i = 0; i < 3; i++)
		{

			if (str[i] == '\0')
			{
				i = 3;
			}
			else if (str[i] > '9' || str[i] < '0' & str[i] != '\0')
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

		_db._ip.fourCell = a;
	} while (a < 0 || a > 255 || !isString == 0);
	fseek(stdin, 0, SEEK_END);

	printf("Enter Name User p.s. only a,b,c... and 1,2,3 other symbols delete! = ");
	scanf("%10s", &_db.name_user);
	ClearTrash(_db.name_user, 10);
	fseek(stdin, 0, SEEK_END);


	printf("\nEnter SurName User p.s. only a,b,c... and 1,2,3 other symbols delete!  = ");
	scanf("%10s", &_db.surname_user);
	ClearTrash(_db.surname_user, 10);
	fseek(stdin, 0, SEEK_END);

	printf("\nEnter Name PC p.s. only a,b,c... and 1,2,3 other symbols delete!  = ");
	scanf("%10s", &_db.name_pc);
	fseek(stdin, 0, SEEK_END);
	ClearTrash(_db.name_pc, 10);


	printf("\nEnter Groupe user p.s. only a,b,c... and 1,2,3 other symbols delete!  = ");

	scanf("%5s", &_db.groupe_user);
	fseek(stdin, 0, SEEK_END);
	ClearTrash(_db.groupe_user, 5);


	if (lenghtTypesPC == 0)
	{
		printf("\n���� ������� ���� ��\n");
		AddInListTypePC();
		_db.typePC = typesPC[0];
	}
	else
	{
		char choice = '0';
		int b = 0;
		do
		{
			printf("\n������ �� �� �������� ����� ��� ��? ���� �� �� ������� Y(y), ����� N(n) = ");
			scanf("%c", &choice);
			fseek(stdin, 0, SEEK_END);
			switch (choice)
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
		if (choice == 'y' || choice == 'Y')
		{
			AddInListTypePC();
			do
			{
				printf("\n������ �� �� �������� ����� ��� �� � �������� ���� ������� �� ��� ������� ������ ���? ���� �� �� ������� Y(y), ����� N(n) = ");
				scanf("%c", &choice); 
				fseek(stdin, 0, SEEK_END);
				switch (choice)
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
			if (choice == 'y' || choice == 'Y')
			{
				_db.typePC = typesPC[lenghtTypesPC-1];
			}
			else
			{
				int choIce = -1;
				printf("�������� ��� �� �� ������ � ������� ���������� ����� ���� �����:");
				for (int i = 0; i < lenghtTypesPC; i++)
				{
					printf("\n%d) %s", i, typesPC[i]);
				}
				do
				{
					printf("������� ���������� ����� �� 0 �� %d", lenghtTypesPC - 1);
					scanf("%d", &choIce);
				} while (choIce < 0 || choIce >= lenghtTypesPC);
				_db.typePC = typesPC[choIce];
			}
		}
		else
		{
			int choIce = -1;
			printf("�������� ��� �� �� ������ � ������� ���������� ����� ���� �����:");
			for (int i = 0; i < lenghtTypesPC; i++)
			{
				printf("\n%d) %s", i, typesPC[i].nameType);
			}
			do
			{
				printf("������� ���������� ����� �� 0 �� %d", lenghtTypesPC - 1);
				scanf("%d", &choIce);
			} while (choIce < 0 || choIce >= lenghtTypesPC);
			_db.typePC = typesPC[choIce];
		}
	}
	fseek(stdin, 0, SEEK_END);
	return _db;
}


//���������� �������� ����� ����������
void addelem(struct list *head) {

	struct list *temp, *p, *cur = NULL;
	int i = 0, a = -1;
	fseek(stdin, 0, SEEK_END);
	if (head->next != NULL)
	{
		do
		{
			printf("\nEnter the element after which you want to add the element = ");
			scanf("%d", &a);
		} while (a == -1);
		cur = head;
		if (a > 0)
		{
			while (i < a & cur->next != NULL)
			{
				cur = cur->next;
				i++;
			}
		}
		if (cur->next != NULL)
		{
			if (i == a)
			{
				struct db newItem = dbEnterData();
				temp = (struct list*)malloc(sizeof(struct list));
				p = cur->next; // ���������� ��������� �� ��������� ����
				cur->next = temp; // ���������� ���� ��������� �� �����������
				temp->_db = newItem; // ���������� ���� ������ ������������ ����
				temp->next = p; // ��������� ���� ��������� �� ��������� ����
				temp->prev = cur; // ��������� ���� ��������� �� ���������� ����
				if (p != NULL)
					p->prev = temp;
				lenghtLists++;
			}
			else
			{
				printf("Not element #%d", a - 1);
			}
		}
		else
		{
			printf("Not element #%d", a - 1);
		}
	}
	else {
		printf("This element == head!!! & head->next = NULL!!!!");
	}
}

//���������� �������� ����� ����������
void addElemToEnd(struct list *head) {

	struct list *temp, *cur;

	cur = head;

	while (cur->next != NULL)
	{
		cur = cur->next;
	}


	struct db newItem = dbEnterData();
	temp = (struct list*)malloc(sizeof(struct list));
	cur->next = temp; // ���������� ���� ��������� �� �����������
	temp->_db = newItem; // ���������� ���� ������ ������������ ����
	temp->prev = cur; // ��������� ���� ��������� �� ���������� ����
	temp->next = NULL;
	lenghtLists++;
}

void deletelem(struct list *lst) {
	struct list *cur = lst, *prev, *next;
	int a = 0, i = 0;
	do
	{
		printf("\nEnter the element after which you want to delete the element = ");
		scanf("%d", &a);
	} while (a == -1);
	if (a > 0)
	{
		while (i < a & cur->next != NULL)
		{
			cur = cur->next;
			i++;
		}
		if (i == a)
		{
			prev = cur->prev; // ����, �������������� lst
			next = cur->next; // ����, ��������� �� lst
			if (prev != NULL)
				prev->next = cur->next; // ������������ ���������
			if (next != NULL)
				next->prev = cur->prev; // ������������ ���������
			free(cur); // ����������� ������ ���������� ��������
			lenghtLists--;
		}
		else
		{
			printf("Not element #%d", a - 1);
		}
	}
	else
	{
		printf("This element == head!!!");
	}
}

void DeleteEndElement(struct list *root)
{
	struct list *cur = root;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	if (cur != root)
	{
		cur->prev->next = NULL;
		free(cur);
		printf("Element deleting!");
		lenghtLists--;
	}
	else
	{
		printf("This element == head!!!");
	}
}

struct list * deleteHead(struct list *root) {
	struct list *temp;
	if (root->next != NULL)
	{
		temp = root->next;
		free(root);
		printf("Element deleting!");
		lenghtLists--;
		return temp;
	}
	else
	{
		printf("Only head there is in the list!!!");
		return temp;
	}
}

void dbPrint(struct db _db)
{
	//����� IP
	printf("IP = %d.%d.%d.%d \n", _db._ip.oneCell, _db._ip.twoCell, _db._ip.threeCell, _db._ip.fourCell);
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

void EditElement(struct list *head)
{
	struct list *cur = head;
	int lenght, i = 0;
	do
	{
		printf("Enter index editing element = ");
		scanf("%d", &lenght);
	} while (lenght < 0);
	while (i < lenght & cur->next != NULL)
	{
		cur = cur->next;
		i++;
	}
	if (i == lenght)
	{
		printf("Select the item you want to edit \n");
		printf("1)IP\n");
		printf("2)Name user\n");
		printf("3)Surname user\n");
		printf("4)Groupe user\n");
		printf("5)Name PC\n");
		printf("6)Type PC\n");
		printf("Enter you choice = ");
		int choice;
		int type;
		int a = 0, isString = 0;
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Select the part IP you want to edit : 1,2,3,4\n");
			int choiceIP;
			do
			{
				scanf("%d", &choiceIP);
			} while (choiceIP < 1 || choiceIP >4);
			printf("Enter of IP\n p.s. interval from 0 to 255\n");
			int a;
			switch (choiceIP)
			{
			case 1:
				do
				{
					a = 0;
					isString = 0;
					char str[3];
					printf("Enter 1 part IP = ");
					scanf("%3s", &str);
					fseek(stdin, 0, SEEK_END);
					for (int i = 0; i < 3; i++)
					{

						if (str[i] == '\0')
						{
							i = 3;
						}
						else if (str[i] > '9' || str[i] < '0' & str[i] != '\0')
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

					cur->_db._ip.oneCell = a;
				} while (a < 0 || a > 255 || !isString == 0);
				break;
			case 2:
				do
				{
					a = 0;
					isString = 0;
					char str[3];
					printf("Enter 2 part IP = ");
					scanf("%3s", &str);
					fseek(stdin, 0, SEEK_END);
					for (int i = 0; i < 3; i++)
					{

						if (str[i] == '\0')
						{
							i = 3;
						}
						else if (str[i] > '9' || str[i] < '0' & str[i] != '\0')
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

					cur->_db._ip.twoCell = a;
				} while (a < 0 || a > 255 || !isString == 0);
				break;
			case 3:
				do
				{
					a = 0;
					isString = 0;
					char str[3];
					printf("Enter 3 part IP = ");
					scanf("%3s", &str);
					fseek(stdin, 0, SEEK_END);
					for (int i = 0; i < 3; i++)
					{

						if (str[i] == '\0')
						{
							i = 3;
						}
						else if (str[i] > '9' || str[i] < '0' & str[i] != '\0')
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

					cur->_db._ip.threeCell = a;
				} while (a < 0 || a > 255 || !isString == 0);
				break;
			case 4:
				do
				{
					a = 0;
					isString = 0;
					char str[3];
					printf("Enter 4 part IP = ");
					scanf("%3s", &str);
					fseek(stdin, 0, SEEK_END);
					for (int i = 0; i < 3; i++)
					{

						if (str[i] == '\0')
						{
							i = 3;
						}
						else if (str[i] > '9' || str[i] < '0' & str[i] != '\0')
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

					cur->_db._ip.fourCell = a;
				} while (a < 0 || a > 255 || !isString == 0);
				fseek(stdin, 0, SEEK_END);
				break;


			}
			fseek(stdin, 0, SEEK_END);
			break;
		case 2:
			printf("Enter Name User p.s. only a,b,c... and 1,2,3 other symbols delete! = ");
			scanf("%10s", &cur->_db.name_user);
			ClearTrash(cur->_db.name_user, 10);
			fseek(stdin, 0, SEEK_END);
			break;
		case 3:
			printf("\nEnter SurName User p.s. only a,b,c... and 1,2,3 other symbols delete!  = ");
			scanf("%10s", &cur->_db.surname_user);
			ClearTrash(cur->_db.surname_user, 10);
			fseek(stdin, 0, SEEK_END);
			break;
		case 4:
			printf("\nEnter Groupe user p.s. only a,b,c... and 1,2,3 other symbols delete!  = ");

			scanf("%5s", &cur->_db.groupe_user);
			fseek(stdin, 0, SEEK_END);
			ClearTrash(cur->_db.groupe_user, 5);
			break;
		case 5:
			printf("\nEnter Name PC p.s. only a,b,c... and 1,2,3 other symbols delete!  = ");
			scanf("%10s", &cur->_db.name_pc);
			fseek(stdin, 0, SEEK_END);
			ClearTrash(cur->_db.name_pc, 10);
			break;
		case 6:

			do
			{
				printf("\nEnter Type PC \n p.s. 0 -> one type, 1 -> two type, 2 -> three type \n = ");
				scanf("%d", &type);
			} while (!(type == 1 || type == 2 || type == 0));
			/*switch (type)
			{
			case 0:
				cur->_db.typePC = 0;
				break;
			case 1:
				cur->_db.typePC = 1;
				break;
			case 2:
				cur->_db.typePC = 2;
				break;
			}*/
			fseek(stdin, 0, SEEK_END);
			break;
		}
	}
	else {
		printf("This is element not exist!!!\n");
	}
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

struct list * Swap(struct list *first, struct list *second, struct list *head)
{

	struct db buf;
	buf = first->_db;
	first->_db = second->_db;
	second->_db = buf;

	return head;
}

struct list * SortByName(struct list *head)
{
	struct list *p = head;
	int index = 0;
	if (lenghtLists == 1)
	{
		printf("���������� �� ����� ���� ��������� �.�. � ������ ����� ���� ���� �������!");
		return head;
	}
	else if (lenghtLists == 2)
	{
		if (p->_db.name_user[0] > p->next->_db.name_user[0])
		{
			return head = Swap(p, p->next, head);
		}
	}
	else
	{
		int numSwap = 0;
		do
		{
			numSwap = 0;
			index = 0;
			p = head;
			while (index < lenghtLists - 1)
			{
				if (index <= lenghtLists - 2)
				{
					if (p->_db.name_user[0] > p->next->_db.name_user[0])
					{
						head = Swap(p, p->next, head);
						numSwap++;
					}
				}
				p = p->next;
				index++;
			}
		} while (numSwap > 0);
		return head;
	}
}

struct list * SortByTypePC(struct list *head)
{
	struct list *p = head;
	int index = 0;
	if (lenghtLists == 1)
	{
		printf("���������� �� ����� ���� ��������� �.�. � ������ ����� ���� ���� �������!");
		return head;
	}
	else if (lenghtLists == 2)
	{
		if (p->_db.typePC.typeNum > p->next->_db.typePC.typeNum)
		{
			return head = Swap(p, p->next, head);
		}
	}
	else
	{
		int numSwap = 0;
		do
		{
			numSwap = 0;
			index = 0;
			p = head;
			while (index < lenghtLists - 1)
			{
				if (index <= lenghtLists - 2)
				{
					if (p->_db.typePC.typeNum > p->next->_db.typePC.typeNum)
					{
						head = Swap(p, p->next, head);
						numSwap++;
					}
				}
				p = p->next;
				index++;
			}
		} while (numSwap > 0);
		return head;
	}
}

struct list * SortBySurname(struct list *head)
{
	struct list *p = head;
	int index = 0;
	if (lenghtLists == 1)
	{
		printf("���������� �� ����� ���� ��������� �.�. � ������ ����� ���� ���� �������!");
		return head;
	}
	else if (lenghtLists == 2)
	{
		if (p->_db.surname_user[0] > p->next->_db.surname_user[0])
		{
			return head = Swap(p, p->next, head);
		}
	}
	else
	{
		int numSwap = 0;
		do
		{
			numSwap = 0;
			index = 0;
			p = head;
			while (index < lenghtLists - 1)
			{
				if (index <= lenghtLists - 2)
				{
					if (p->_db.surname_user[0] > p->next->_db.surname_user[0])
					{
						head = Swap(p, p->next, head);
						numSwap++;
					}
				}
				p = p->next;
				index++;
			}
		} while (numSwap > 0);
		return head;
	}
}

struct list * SortByNamePc(struct list *head)
{
	struct list *p = head;
	int index = 0;
	if (lenghtLists == 1)
	{
		printf("���������� �� ����� ���� ��������� �.�. � ������ ����� ���� ���� �������!");
		return head;
	}
	else if (lenghtLists == 2)
	{
		if (p->_db.name_pc[0] > p->next->_db.name_pc[0])
		{
			return head = Swap(p, p->next, head);
		}
	}
	else
	{
		int numSwap = 0;
		do
		{
			numSwap = 0;
			index = 0;
			p = head;
			while (index < lenghtLists - 1)
			{
				if (index <= lenghtLists - 2)
				{
					if (p->_db.name_pc[0] > p->next->_db.name_pc[0])
					{
						head = Swap(p, p->next, head);
						numSwap++;
					}
				}
				p = p->next;
				index++;
			}
		} while (numSwap > 0);
		return head;
	}
}

struct list * SortByGroupeUser(struct list *head)
{
	struct list *p = head;
	int index = 0;
	if (lenghtLists == 1)
	{
		printf("���������� �� ����� ���� ��������� �.�. � ������ ����� ���� ���� �������!");
		return head;
	}
	else if (lenghtLists == 2)
	{
		if (p->_db.groupe_user[0] > p->next->_db.groupe_user[0])
		{
			return head = Swap(p, p->next, head);
		}
	}
	else
	{
		int numSwap = 0;
		do
		{
			numSwap = 0;
			index = 0;
			p = head;
			while (index < lenghtLists - 1)
			{
				if (index <= lenghtLists - 2)
				{
					if (p->_db.groupe_user[0] > p->next->_db.groupe_user[0])
					{
						head = Swap(p, p->next, head);
						numSwap++;
					}
				}
				p = p->next;
				index++;
			}
		} while (numSwap > 0);
		return head;
	}
}


void Menu(struct list *head)
{
	while (1)
	{
		if (head == NULL)
		{
			system("cls");
			printf("Enter the number that indicates your choice.\n");
			printf("1)Add element\n");
			printf("2)Exit \nEnter = ");
			int choice;
			scanf("%d", &choice);
			struct db _db;
			switch (choice)
			{
			case 1:
				_db = dbEnterData();
				head = init(_db);
				break;
			case 2:
				return;
				break;
			}
		}
		else
		{
			system("cls");
			printf("Enter the number that indicates your choice.\n");
			printf("1)Add element between  element's \n");
			printf("2)Add element to end list\n");
			printf("3)Edit element\n");
			printf("4)Delete element between element's\n");
			printf("5)Delete end element\n");
			printf("6)Delete head element\n");
			printf("7)Print list's\n");
			printf("8)���������� �� �����\n");
			printf("9)���������� �� �������\n");
			printf("10)���������� �� ������ ������������\n");
			printf("11)���������� �� ���� ��\n");
			printf("12)���������� �� ����� ��\n");
			printf("13)Exit\nEnter = ");
			int choice;
			scanf("%d", &choice);
			switch (choice)
			{
			case 1:
				addelem(head);
				break;
			case 2:
				addElemToEnd(head);
				break;
			case 3:
				EditElement(head);
				break;
			case 4:
				deletelem(head);
				break;
			case 5:
				DeleteEndElement(head);
				break;
			case 6:
				head = deleteHead(head);
				break;
			case 7:
				listPrint(head);
				break;
			case 8:
				head = SortByName(head);
				break;
			case 9:
				head = SortBySurname(head);
				break;
			case 10:
				head = SortByGroupeUser(head);
				break;
			case 11:
				head = SortByTypePC(head);
				break;
			case 12:
				head = SortByNamePc(head);
				break;
			case 13:
				return;
				break;
			}
			getchar(); getchar();
		}
	}
}
int main()
{
	system("chcp 1251");
	struct list *head = NULL/* "������" �����*/;
	Menu(head);
	return 0;
}