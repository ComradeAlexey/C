#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct TypePC *typesPC = NULL;
int lenghtTypesPC = 0;
int lenghtLists = 0;
struct ip
{
	unsigned char oneCell;//первая ячейка адресса
	unsigned char twoCell;//вторая ячейка адресса
	unsigned char threeCell;//третья ячейка адресса
	unsigned char fourCell;//четвёртая ячейка адресса
};

struct editIP
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
	struct ip _ip;//структура ip адресса, состоит из четырёх переменных, каждая из которых отвечает за свою ячейку адресса
	char name_pc[10];//название ПК
	char name_user[10];//Имя пользователя
	char surname_user[10];//Фамилия пользователя
	char groupe_user[5];//Название группы
	struct TypePC typePC;//Тип ПК
};

struct list
{
	struct db _db; // поле данных
	struct list *next; // указатель на следующий элемент
	struct list *prev; // указатель на предыдущий элемент
};

struct list * init(struct db a)  // а - значение первого узла
{
	struct list *lst;
	// выделение памяти под корень списка
	lst = (struct list*)malloc(sizeof(struct list));
	//присвоение данных
	lst->_db = a;
	lst->next = NULL; // указатель на следующий узел
	lst->prev = NULL; // указатель на предыдущий узел
	lenghtLists++;
	return(lst);
}

void AddInListTypePC()
{
	
	typesPC = (struct  TypePC*)realloc(typesPC, lenghtTypesPC * sizeof(struct  TypePC));

	printf("Вводите название типа ПК = ");
	typesPC[lenghtTypesPC].typeNum = lenghtTypesPC;
	lenghtTypesPC++;
	scanf("%s", typesPC[lenghtTypesPC - 1].nameType);
}

void PrintListTypePC()
{
	for (int i = 0; i < lenghtTypesPC; i++)
	{
		printf("\n Номер элемента списка типов ПК %d содержимое %s", i, typesPC[i].nameType);
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
	//ввод IP
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
		printf("\nВвод первого типа ПК\n");
		AddInListTypePC();
		_db.typePC = typesPC[0];
	}
	else
	{
		char choice = '0';
		int b = 0;
		do
		{
			printf("\nХотите ли Вы добавить новый тип ПК? Если да то введите Y(y), иначе N(n) = ");
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
				printf("\nХотите ли Вы добавить новый тип ПК в качестве типа данного ПК или выбрать другой тип? Если да то введите Y(y), иначе N(n) = ");
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
				printf("\nВыберите тип ПК из списка и введите порядковый номер типа далее:");
				for (int i = 0; i < lenghtTypesPC; i++)
				{
					printf("\n%d) %s", i, typesPC[i]);
				}
				do
				{
					printf("\nВведите порядковый номер от 0 до %d = ", lenghtTypesPC - 1);
					scanf("%d", &choIce);
				} while (choIce < 0 || choIce >= lenghtTypesPC);
				_db.typePC = typesPC[choIce];
			}
		}
		else
		{
			int choIce = -1;
			printf("Выберите тип ПК из списка и введите порядковый номер типа далее:");
			for (int i = 0; i < lenghtTypesPC; i++)
			{
				printf("\n%d) %s\n", i, typesPC[i].nameType);
			}
			do
			{
				printf("Введите порядковый номер от 0 до %d = ", lenghtTypesPC - 1);
				scanf("%d", &choIce);
			} while (choIce < 0 || choIce >= lenghtTypesPC);
			_db.typePC = typesPC[choIce];
		}
	}
	fseek(stdin, 0, SEEK_END);
	return _db;
}


//добавление элемента между элементами
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
				p = cur->next; // сохранение указателя на следующий узел
				cur->next = temp; // предыдущий узел указывает на создаваемый
				temp->_db = newItem; // сохранение поля данных добавляемого узла
				temp->next = p; // созданный узел указывает на следующий узел
				temp->prev = cur; // созданный узел указывает на предыдущий узел
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

//добавление элемента между элементами
void addElemToEnd(struct list *head) {

	struct list *temp, *cur;

	cur = head;

	while (cur->next != NULL)
	{
		cur = cur->next;
	}


	struct db newItem = dbEnterData();
	temp = (struct list*)malloc(sizeof(struct list));
	cur->next = temp; // предыдущий узел указывает на создаваемый
	temp->_db = newItem; // сохранение поля данных добавляемого узла
	temp->prev = cur; // созданный узел указывает на предыдущий узел
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
			prev = cur->prev; // узел, предшествующий lst
			next = cur->next; // узел, следующий за lst
			if (prev != NULL)
				prev->next = cur->next; // переставляем указатель
			if (next != NULL)
				next->prev = cur->prev; // переставляем указатель
			free(cur); // освобождаем память удаляемого элемента
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
struct editIP EditIP(int numPart)
{
	struct editIP edit;
	int a = 0, isString = 0;
	a = 0;
	isString = 0;
	char str[3];
	printf("Введите %d часть IP = ", numPart);
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
		printf("Введите индекс редактируемого элемента(отчёт начинается с 0) = ");
		scanf("%d", &lenght);
	} while (lenght < 0);
	while (i < lenght & cur->next != NULL)
	{
		cur = cur->next;
		i++;
	}
	if (i == lenght)
	{
		printf("выберите пункт который хотите редактировать\n");
		printf("1)IP\n");
		printf("2)Имя пользователя\n");
		printf("3)Фамилию пользователя\n");
		printf("4)Группу пользователя\n");
		printf("5)Имя ПК\n");
		printf("6)Тип ПК\n");
		printf("Введите число = ");
		int choice;
		int type;
		
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Выберите часть IP которую хотите редактировать : 1,2,3,4\n");
			int choiceIP;
			do
			{
				scanf("%d", &choiceIP);
			} while (choiceIP < 1 || choiceIP >4);
			printf("Введите IP\n p.s. интервал значения от 0 до 255\n");
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
			printf("Введите имя пользователя p.s. только a,b,c... и 1,2,3, остальные символы удаляются! = ");
			scanf("%10s", &cur->_db.name_user);
			ClearTrash(cur->_db.name_user, 10);
			fseek(stdin, 0, SEEK_END);
			break;
		case 3:
			printf("\nВведите фамилию пользователя p.s. only a,b,c... and 1,2,3 other symbols delete!  = ");
			scanf("%10s", &cur->_db.surname_user);
			ClearTrash(cur->_db.surname_user, 10);
			fseek(stdin, 0, SEEK_END);
			break;
		case 4:
			printf("\nВведите группу пользователя пользователя p.s. only a,b,c... and 1,2,3 other symbols delete!  = ");

			scanf("%5s", &cur->_db.groupe_user);
			fseek(stdin, 0, SEEK_END);
			ClearTrash(cur->_db.groupe_user, 5);
			break;
		case 5:
			printf("\nВведите имя ПК p.s. only a,b,c... and 1,2,3 other symbols delete!  = ");
			scanf("%10s", &cur->_db.name_pc);
			fseek(stdin, 0, SEEK_END);
			ClearTrash(cur->_db.name_pc, 10);
			break;
		/*case 6:

			do
			{
				printf("\nВведите имя пользователя \n p.s. 0 -> one type, 1 -> two type, 2 -> three type \n = ");
				scanf("%d", &type);
			} while (!(type == 1 || type == 2 || type == 0));
			fseek(stdin, 0, SEEK_END);
			break;*/
		}
	}
	else {
		printf("Данного элемента нету в списке!!!\n");
	}
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
		printf("Сортировка не может быть выполнена т.к. в списке всего лишь один элемент!");
		return head;
	}
	else if (lenghtLists == 2)
	{
		if (p->_db.name_user[0] > p->next->_db.name_user[0])
		{
			printf("Сортировка выполнена!");
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
		printf("Сортировка выполнена!");
		return head;
	}
}

struct list * SortByTypePC(struct list *head)
{
	struct list *p = head;
	int index = 0;
	if (lenghtLists == 1)
	{
		printf("Сортировка не может быть выполнена т.к. в списке всего лишь один элемент!");
		return head;
	}
	else if (lenghtLists == 2)
	{
		if (p->_db.typePC.typeNum > p->next->_db.typePC.typeNum)
		{
			printf("Сортировка выполнена!");
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
		printf("Сортировка выполнена!");
		return head;
	}
}

struct list * SortBySurname(struct list *head)
{
	struct list *p = head;
	int index = 0;
	if (lenghtLists == 1)
	{
		printf("Сортировка не может быть выполнена т.к. в списке всего лишь один элемент!");
		return head;
	}
	else if (lenghtLists == 2)
	{
		if (p->_db.surname_user[0] > p->next->_db.surname_user[0])
		{
			printf("Сортировка выполнена!");
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
		printf("Сортировка выполнена!");
		return head;
	}
}

struct list * SortByNamePc(struct list *head)
{
	struct list *p = head;
	int index = 0;
	if (lenghtLists == 1)
	{
		printf("Сортировка не может быть выполнена т.к. в списке всего лишь один элемент!");
		return head;
	}
	else if (lenghtLists == 2)
	{
		if (p->_db.name_pc[0] > p->next->_db.name_pc[0])
		{
			printf("Сортировка выполнена!");
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
		printf("Сортировка выполнена!");
		return head;
	}
}

struct list * SortByGroupeUser(struct list *head)
{
	struct list *p = head;
	int index = 0;
	if (lenghtLists == 1)
	{
		printf("Сортировка не может быть выполнена т.к. в списке всего лишь один элемент!");
		return head;
	}
	else if (lenghtLists == 2)
	{
		if (p->_db.groupe_user[0] > p->next->_db.groupe_user[0])
		{
			printf("Сортировка выполнена!");
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
		printf("Сортировка выполнена!");
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
			printf("Введите нужный Вам пункт\n");
			printf("1)Добавить корневой элемент\n");
			printf("2)Выйти\nВведите число = ");
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
			printf("Введите нужный Вам пункт\n");
			printf("1)Добавить элемент между элементами\n");
			printf("2)Добавить элемент в конец списка\n");
			printf("3)Редактировать элемент\n");
			printf("4)Удалить элемент между элементами\n");
			printf("5)Удалить последний в списке элемент\n");
			printf("6)Удалить корневой элемент\n");
			printf("7)Вывести все элементы\n");
			printf("8)Сортировка по имени\n");
			printf("9)Сортировка по фамилии\n");
			printf("10)Сортировка по группе пользователя\n");
			printf("11)Сортировка по типу ПК\n");
			printf("12)Сортировка по имени ПК\n");
			printf("13)Выйти\nВведите число = ");
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
	struct list *head = NULL/* "голова" листа*/;
	Menu(head);
	return 0;
}