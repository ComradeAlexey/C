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

	for (char i = '�'; i <= '�'; i++)
	{
		if (c == i)
			isTrash++;
	}
	for (char i = '�'; i <= '�'; i++)
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
struct addIP AddPartIP(int numPart)
{
	struct addIP add;
	int a = 0, isString = 0;
	a = 0;
	isString = 0;
	char str[4];
	printf("������� %d ����� IP = ", numPart);
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

char *AddString(char *name ,int lenghtString)
{
	char *str;
	str = (char *)malloc(sizeof(char) * lenghtString);
	printf("Enter %s p.s. only a,b,c... and 1,2,3 other symbols delete! = ", name);
	scanf("%10s", &str);
	ClearTrash(str, lenghtString);
	fseek(stdin, 0, SEEK_END);
	return str;
}
struct db dbEnterData()
{
	struct db _db;
	struct addIP add;
	//���� IP
	printf("Enter of IP\n p.s. interval from 0 to 255\n");
	int a = 0, isString = 0, isNull1, isNull2;

	_db._ip.oneCell = AddIP(1);
	_db._ip.twoCell = AddIP(2);
	_db._ip.threeCell = AddIP(3);
	_db._ip.fourCell = AddIP(4);

	*_db.name_user = AddString("Name User", 10);
	*_db.surname_user = AddString("SurName User", 10);
	*_db.name_pc = AddString("Name PC", 10);
	*_db.groupe_user = AddString("Groupe user", 5);

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
				_db.typePC = typesPC[lenghtTypesPC - 1];
			}
			else
			{
				int choIce = -1;
				printf("\n�������� ��� �� �� ������ � ������� ���������� ����� ���� �����:");
				for (int i = 0; i < lenghtTypesPC; i++)
				{
					printf("\n%d) %s", i, typesPC[i]);
				}
				do
				{
					printf("\n������� ���������� ����� �� 0 �� %d = ", lenghtTypesPC - 1);
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
				printf("\n%d) %s\n", i, typesPC[i].nameType);
			}
			do
			{
				printf("������� ���������� ����� �� 0 �� %d = ", lenghtTypesPC - 1);
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
struct editIP EditIP(int numPart)
{
	struct editIP edit;
	int a = 0, isString = 0;
	a = 0;
	isString = 0;
	char str[3];
	printf("������� %d ����� IP = ", numPart);
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
	edit.a = a;
	edit.isString = isString;
	return edit;
}
void EditElement(struct list *head)
{
	struct list *cur = head;
	int lenght, i = 0;
	do
	{
		printf("������� ������ �������������� ��������(����� ���������� � 0) = ");
		scanf("%d", &lenght);
	} while (lenght < 0);
	while (i < lenght & cur->next != NULL)
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
		int type;
		
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("�������� ����� IP ������� ������ ������������� : 1,2,3,4\n");
			int choiceIP;
			do
			{
				scanf("%d", &choiceIP);
			} while (choiceIP < 1 || choiceIP >4);
			printf("������� IP\n p.s. �������� �������� �� 0 �� 255\n");
			struct editIP edit;
			switch (choiceIP)
			{
			case 1:
				do
				{
					edit = EditIP(1);
				} while (edit.a < 0 || edit.a > 255 || !edit.isString == 0);
				cur->_db._ip.oneCell = edit.a;
				break;
			case 2:
				do
				{
					edit = EditIP(2);
				} while (edit.a < 0 || edit.a > 255 || !edit.isString == 0);
				cur->_db._ip.twoCell = edit.a;
				break;
			case 3:
				do
				{
					edit = EditIP(3);
				} while (edit.a < 0 || edit.a > 255 || !edit.isString == 0);
				cur->_db._ip.threeCell = edit.a;
				break;
			case 4:
				do
				{
					edit = EditIP(4);
				} while (edit.a < 0 || edit.a > 255 || !edit.isString == 0);
				cur->_db._ip.fourCell = edit.a;
				break;
			}
			fseek(stdin, 0, SEEK_END);
			break;
		case 2:
			printf("������� ��� ������������ p.s. ������ a,b,c... � 1,2,3, ��������� ������� ���������! = ");
			scanf("%10s", &cur->_db.name_user);
			ClearTrash(cur->_db.name_user, 10);
			fseek(stdin, 0, SEEK_END);
			break;
		case 3:
			printf("\n������� ������� ������������ p.s. only a,b,c... and 1,2,3 other symbols delete!  = ");
			scanf("%10s", &cur->_db.surname_user);
			ClearTrash(cur->_db.surname_user, 10);
			fseek(stdin, 0, SEEK_END);
			break;
		case 4:
			printf("\n������� ������ ������������ ������������ p.s. only a,b,c... and 1,2,3 other symbols delete!  = ");

			scanf("%5s", &cur->_db.groupe_user);
			fseek(stdin, 0, SEEK_END);
			ClearTrash(cur->_db.groupe_user, 5);
			break;
		case 5:
			printf("\n������� ��� �� p.s. only a,b,c... and 1,2,3 other symbols delete!  = ");
			scanf("%10s", &cur->_db.name_pc);
			fseek(stdin, 0, SEEK_END);
			ClearTrash(cur->_db.name_pc, 10);
			break;
		/*case 6:

			do
			{
				printf("\n������� ��� ������������ \n p.s. 0 -> one type, 1 -> two type, 2 -> three type \n = ");
				scanf("%d", &type);
			} while (!(type == 1 || type == 2 || type == 0));
			fseek(stdin, 0, SEEK_END);
			break;*/
		}
	}
	else {
		printf("������� �������� ���� � ������!!!\n");
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
int BoolReturnNameUser(struct list *p)
{
	if (p->_db.name_user[0] > p->next->_db.name_user[0])
	{
		return 1;
	}
	else
		return 0;
}
int BoolReturnNameTypePC(struct list *p)
{
	if (p->_db.typePC.nameType[0] > p->next->_db.typePC.nameType[0])
	{
		return 1;
	}
	else
		return 0;
}
int BoolReturnSurnameUser(struct list *p)
{
	if (p->_db.surname_user[0] > p->next->_db.surname_user[0])
	{
		return 1;
	}
	else
		return 0;
}
int BoolReturnGroupeUser(struct list *p)
{
	if (p->_db.groupe_user[0] > p->next->_db.groupe_user[0])
	{
		return 1;
	}
	else
		return 0;
}
int BoolReturnNamePC(struct list *p)
{
	if (p->_db.name_pc[0] > p->next->_db.name_pc[0])
	{
		return 1;
	}
	else
		return 0;
}
struct list * SwapInAscendingSort(struct list *p, struct list *head, int *numSwap, int typeSort)
{
	int resultBool = 0, _numSwap;
	switch (typeSort)
	{
	case 1:
		resultBool = BoolReturnNameUser(p);
		break;
	case 2:
		resultBool = BoolReturnSurnameUser(p);
		break;
	case 3:
		resultBool = BoolReturnGroupeUser(p);
		break;
	case 4:
		resultBool = BoolReturnNamePC(p);
		break;
	case 5:
		resultBool = BoolReturnNameTypePC(p);
		break;
	}
	if (resultBool == 1)
	{
		head = Swap(p, p->next, head);
		_numSwap = *numSwap;
		_numSwap++;
		numSwap = &_numSwap;
		return head;
	}
}
struct list * AscendingSort(struct list *head, int typeSort)
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
			printf("���������� ���������!");
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
					head = SwapInAscendingSort(p,head, numSwap, typeSort);
				}
				p = p->next;
				index++;
			}
		} while (numSwap > 0);
		printf("���������� ���������!");
		return head;
	}
}



void Menu(struct list *head)
{
	while (1)
	{
		system("cls");
		if (head == NULL)
		{
			printf("������� ������ ��� �����\n");
			printf("1)�������� �������� �������\n");
			printf("2)�����\n������� ����� = ");
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
			printf("������� ������ ��� �����\n");
			printf("1)�������� ������� ����� ����������\n");
			printf("2)�������� ������� � ����� ������\n");
			printf("3)������������� �������\n");
			printf("4)������� ������� ����� ����������\n");
			printf("5)������� ��������� � ������ �������\n");
			printf("6)������� �������� �������\n");
			printf("7)������� ��� ��������\n");
			printf("8)���������� �� �����\n");
			printf("9)���������� �� �������\n");
			printf("10)���������� �� ������ ������������\n");
			printf("11)���������� �� ���� ��\n");
			printf("12)���������� �� ����� ��\n");
			printf("13)�����\n������� ����� = ");
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
				head = AscendingSort(head,1);
				break;
			case 9:
				head = AscendingSort(head,2);
				break;
			case 10:
				head = AscendingSort(head,3);
				break;
			case 11:
				head = AscendingSort(head,5);
				break;
			case 12:
				head = AscendingSort(head,4);
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