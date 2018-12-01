#include<stdio.h> 
#include <locale.h> 
int main() 
{ 
setlocale(LC_ALL, "Rus"); 
int arr[10]; 
for (int i = 0; i < 10; i++) 
{ 
printf("Введите число \n"); 
scanf("%d", &arr[i]); 
} 
printf("\n Исходный массив \n"); 
for (int i = 0; i < 10; i++) 
{ 
printf("%d",arr[i]); 
} 
int a = 1; 
int b; 
while (a > 0) 
{ 
a = 0; 
for (int i = 0; i < 9; i++) 
{ 
if (arr[i] > arr[i + 1]) 
{ 
b = arr[i]; 
arr[i] = arr[i + 1]; 
arr[i + 1] = b; 
a++; 
} 
} 
} 
printf("\n Результат сортировки \n"); 
for (int i = 0; i < 10; i++) 
{ 
printf("%d", arr[i]); 
} 
getchar(); getchar(); 
return 0; 
}
