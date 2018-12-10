#include<stdio.h>
#define N 2//размер поля
int field_hidden[N][N];//мины
char field[N][N];//визуальное отображение поля
int numRe = 3;//Кол-во попыток
void floodFill8(int x, int y, int score);//прототип одноимённой функции
int numMines;//кол-во мин
int checkScore(int x, int y);//прототип одноимённой функции
//стартовый прогон поля, инициализирует все массивы
void clear_field(char c)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			field[i][j] = c;
			field_hidden[i][j] = 0;
		}
	}
}
//устанавливает мины
void set_mine_count(int count)
{
	for (int i = 0; i < count;)
	{
		int x = rand() % N;
		int y = rand() % N;
		if (!field_hidden[x][y])
		{
			field_hidden[x][y] = 1;
			i++;
		}
	}
}
//отображение поля
void show_field()
{
	system("cls");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%c",field[i][j]);
		}
		printf("\n");
	}
}
//показываем расположение мин, тестовая функция
void show_field_h()
{
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d", field_hidden[i][j]);
		}
		printf("\n");
	}
}
//проверка "попадания" игрока по клетке, если false то игра проиграна, иначе продолжаем игру
int shoot(int x, int y)
{
	//проверка на наличие мины, если мина есть и кол-во попыток равно 0 то игра проиграна
	if (field_hidden[y][x] & numRe == 0)
		return 0;
	//проверка на наличие мины, если мина есть и кол-во попыток больше 0 то игра продолжается
	else if (field_hidden[y][x] & numRe > 0)
	{
		numRe--;
		printf("You hit a mine, from now on be careful!!! remaining attempts = %d \n",numRe);
		getchar(); getchar();
		return 1;
	}
	//мины нету, продолжаем, и сразу проверяем соседние клетки на наличие мин, если таковые есть то всё заносится в scorе и в конце цикла на клетке показывается кол-во мин окружающих эту самую клетку
	else 
	{
		
		floodFill8(x, y, 0);
		return 1;
	}
}
//заливка, работу алгоритма можно посмотреть на википедии, так и называется алгоритм заливки.
void floodFill8(int x, int y)
{
	if (x >= 0 && x < N && y >= 0 && y < N)
	{
		if (field_hidden[y][x] != 1 && field[y][x] == '#')
		{
			floodFill8(x + 1, y);
			if (field_hidden[y][x + 1] == 1)
			{
				field[y][x] = checkScore(x, y) + 0x30;
			}
			floodFill8(x - 1, y);
			if (field_hidden[y][x - 1] == 1)
			{
				field[y][x] = checkScore(x, y) + 0x30;
			}
			floodFill8(x, y + 1);
			if (field_hidden[y + 1][x] == 1)
			{
				field[y][x] = checkScore(x, y) + 0x30;
			}
			floodFill8(x, y - 1);
			if (field_hidden[y - 1][x] == 1)
			{
				field[y][x] = checkScore(x, y) + 0x30;
			}
		}
	}
}
//функция подсчитывания клеток с минами вокруг одной взятой клетки без мины
int checkScore(int x, int y)
{
	int score = 0;
	for (int i = y - 1; i < y + 1 && i < N; i++)
	{
		for (int j = x - 1; j < x + 1 && j < N; j++)
		{
			if (j >= 0 & i >= 0)
			{
				if (field_hidden[y][x] == 1)
					score++;
			}
		}
	}
	return score;
}
//проверка на победу
int checkWin()
{
	//просто проходим по всем полям и смотрим сколько клеток "закрашено", при этом эта клетка не должна быть заминирована 
	int score = 0;
	//score это счётчик закрашенных клеток
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (field[y][x] != '#' & field_hidden[y][x] == 0)
				score++;
		}
	}
	//тут мы из общей площади вычитаем кол-во мин и сравниваем со счётчиком, если равны то возвращаем 1, иначе 0
	if (score == N*N - numMines)
		return 1;
	else
		return 0;
}
//главная функция
void game()
{

	clear_field('#');
	//вводим кол-во мин, если ввели в допустимом диапазоне то продолжаем, иначе всё заново
	do
	{
		printf("Enter num mines!!! = ");
		scanf("%d",&numMines);
	} while (numMines > 0 & numMines < N/2);
	//создание минного поля
	set_mine_count(numMines);
	//объявление переменных для координат
	int x, y;
	do
	{
		show_field();
		show_field_h();
		if (checkWin() == 1)
		{
			printf("Win!");
			getchar(); getchar();
			return;
		}
		printf("Enter X & Y \nX = ");
		scanf("%d",&x);
		printf("\nY = ");
		scanf("%d",&y);
	} while (shoot(x, y));
	printf("Game over!!!");
	getchar(); getchar();
}
int main()
{
	game();
	return 0;
}
