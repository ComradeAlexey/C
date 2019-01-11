#include<stdio.h> 
#include <time.h> 
#define N 10//размер поля 
int field_hidden[N][N];//поле мин 
int field_mines_in_cell[N][N];//отображает кол-во мин около отдельно взятой точки 
int field_open[N][N];//является булевым аналогом открытой или закрытой точки. 
int numRe = 3;//Кол-во попыток 
void openCells(int x, int y);//прототип одноимённой функции 
int numMines;//кол-во мин 
int bangMine = 0;//был ли подрыв мины? 
int score = 0;//кол-во открытых клеток 
//стартовый прогон поля, инициализирует все массивы 

void clear_field(char c) 
{ 
for (int i = 0; i < N; i++) 
{ 
for (int j = 0; j < N; j++) 
{ 
field_hidden[i][j] = 0; 
} 
} 
} 
//устанавливает мины 
void set_mine_count(int count) 
{ 

for (int i = 0; i < count;) 
{ 
srand(time(NULL)); 
int x = rand() % N; 
int y = rand() % N; 
if (field_hidden[y][x] == 0) 
{ 
field_hidden[y][x] = 1; 
i++; 
} 
} 
} 
//заносит в field_mines_in_cell кол-во мин около отдельной взятой ячейки поля с координатами х,у 
void set_mines_count() 
{ 
int x, y; 
for (x = 0; x < N; x++) 
for (y = 0; y < N; y++) 
if (field_hidden[y][x] == 0) { 
int count = 0; 
for (int dx = -1; dx < 2; dx++) 
for (int dy = -1; dy < 2; dy++) { 
int nX = x + dx; 
int nY = y + dy; 
//проверка на выход за пределы массива, если вышли то ставим координаты текущей итерации(Прогона цикла, шага цикла) 
if (nX < 0 || nY < 0 || nX > N - 1 || nY > N - 1) { 
nX = x; 
nY = y; 
} 
//если в клетке находится мина то прибавляем 1, иначе 0 
count += (field_hidden[nY][nX] == 1) ? 1 : 0; 
} 
//заносим в массив кол-во мин около клетки 
field_mines_in_cell[y][x] = count; 
} 
} 
//отображение поля 
void show_field() 
{ 
//очищаем поле 
system("cls"); 
for (int i = 0; i < N; i++) 
{ 
for (int j = 0; j < N; j++) 
{ 
//если клетку ещё не открывал игрок или рекурсия то выводим решётку 
if (field_open[i][j] == 0) 
{ 
printf("#"); 
} 
else 
{ 
//если мина находится в данных координатах то выводим решётку 
if (field_hidden[i][j] == 1) 
{ 
printf("#"); 
} 
else 
{ 
//если около клетки есть мины то выводим их кол-во по координатам клетки 
if (field_mines_in_cell[i][j] > 0) 
{ 
printf("%d", field_mines_in_cell[i][j]); 
}//иначе выводим ноль 
else 
{ 
printf("0"); 
} 
} 
} 
} 
//перенос на следующую строку 
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
//показываем расположение открытых ячеек, тестовая функция 
void show_field_o() 
{ 
printf("\n"); 
for (int i = 0; i < N; i++) 
{ 
for (int j = 0; j < N; j++) 
{ 
printf("%d", field_open[i][j]); 
} 
printf("\n"); 
} 
} 
//показываем 
void show_field_nm() 
{ 
printf("\n"); 
for (int i = 0; i < N; i++) 
{ 
for (int j = 0; j < N; j++) 
{ 
printf("%d", field_mines_in_cell[i][j]); 
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

openCells(x, y); 
return 1; 
} 
} 
//метод "открытия" ячейки, в качестве параметров передеаются координаты 
void open(int x,int y) { 
field_open[y][x] = 1; 
bangMine =
field_hidden[y][x]; 
if (!field_hidden[y][x]) score++; 
} 
//рекурсивное открытие ячеек поля 
void openCells(int x, int y) { 
if (x < 0 || x > N - 1 || y < 0 || y > N - 1) return; //плохие координаты 
if (field_open[y][x] == 1) return; //ячейка уже открыта 
open(x, y);//открытие ячейки 
if (field_mines_in_cell[y][x] > 0 || bangMine == 1) return; // ячейка не пуста 
//вызываем рекурсию во все стороны(кроме диагонали) 
openCells(x, y-1); 
openCells(x, y+1); 
openCells(x-1, y); 
openCells(x+1, y); 
} 
//проверка на победу 
int checkWin() 
{ 
//тут мы из общей площади вычитаем кол-во мин и сравниваем со счётчиком, если равны то возвращаем 1, иначе 0 
if (score == N*N - numMines) 
return 1; 
else 
return 0; 
} 
//главная функция 
void game() 
{ 
srand(time(NULL)); 
clear_field('#'); 
//вводим кол-во мин, если ввели в допустимом диапазоне то продолжаем, иначе всё заново 
do 
{ 
printf("Enter num mines!!! = "); 
scanf("%d",&numMines); 
} while (numMines < 0 & numMines > N * N/2); 
//создание минного поля 
set_mine_count(numMines); 
set_mines_count(); 
//объявление переменных для координат 
int x, y; 
//пока не попапи в мину - играем 
do 
{ 
show_field(); 
show_field_h(); 
/*show_field_o(); 
show_field_nm();*/ 
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
