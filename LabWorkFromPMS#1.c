#include<stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	printf("Введите индентификатор который нужно переделать в lCC \n");
	char in_string[1000]; // строковый массив для ввода 
	gets(in_string);
	printf("%s", in_string);
	int StartChar = 0;//был ли стартовый символ?
	for (int i = 0; i < 1000; i++)
	{
		if (StartChar == 0)
		{
			switch (in_string[i])
			{
			case 'Q':in_string[i] = 'q';
				StartChar++;
				break;
			case 'W':in_string[i] = 'w';
				StartChar++;
				break;
			case 'E':in_string[i] = 'e';
				StartChar++;
				break;
			case 'R':in_string[i] = 'r';
				StartChar++;
				break;
			case 'T':in_string[i] = 't';
				StartChar++;
				break;
			case 'Y':in_string[i] = 'y';
				StartChar++;
				break;
			case 'U':in_string[i] = 'u';
				StartChar++;
				break;
			case 'I':in_string[i] = 'i';
				StartChar++;
				break;
			case 'O':in_string[i] = 'o';
				StartChar++;
				break;
			case 'P':in_string[i] = 'p';
				StartChar++;
				break;
			case 'A':in_string[i] = 'a';
				StartChar++;
				break;
			case 'S':in_string[i] = 's';
				StartChar++;
				break;
			case 'D':in_string[i] = 'd';
				StartChar++;
				break;
			case 'F':in_string[i] = 'f';
				StartChar++;
				break;
			case 'G':in_string[i] = 'g';
				StartChar++;
				break;
			case 'H':in_string[i] = 'h';
				StartChar++;
				break;
			case 'J':in_string[i] = 'j';
				StartChar++;
				break;
			case 'K':in_string[i] = 'k';
				StartChar++;
				break;
			case 'L':in_string[i] = 'l';
				StartChar++;
				break;
			case 'Z':in_string[i] = 'z';
				StartChar++;
				break;
			case 'X':in_string[i] = 'x';
				StartChar++;
				break;
			case 'C':in_string[i] = 'c';
				StartChar++;
				break;
			case 'V':in_string[i] = 'v';
				StartChar++;
				break;
			case 'B':in_string[i] = 'b';
				StartChar++;
				break;
			case 'N':in_string[i] = 'n';
				StartChar++;
				break;
			case 'M':in_string[i] = 'm';
				StartChar++;
				break;
			case '_':
				for (int j = i; j < 999; j++)
				{
					in_string[j] = in_string[j + 1];
				}
				i--;
			default:
				break;
			}
		}
		if (StartChar == 1)
		{
			if (in_string[i] == '_')
			{
				switch (in_string[i+1])
				{
				case 'q':in_string[i + 1] = 'Q';
					break;
				case 'w':in_string[i + 1] = 'W';
					break;
				case 'e':in_string[i + 1] = 'E';
					break;
				case 'r':in_string[i + 1] = 'R';
					break;
				case 't':in_string[i + 1] = 'T';
					break;
				case 'y':in_string[i + 1] = 'Y';
					break;
				case 'u':in_string[i + 1] = 'U';
					break;
				case 'i':in_string[i + 1] = 'I';
					break;
				case 'o':in_string[i + 1] = 'O';
					break;
				case 'p':in_string[i + 1] = 'P';
					break;
				case 'a':in_string[i + 1] = 'A';
					break;
				case 's':in_string[i + 1] = 'S';
					break;
				case 'd':in_string[i + 1] = 'D';
					break;
				case 'f':in_string[i + 1] = 'F';
					break;
				case 'g':in_string[i + 1] = 'G';
					break;
				case 'h':in_string[i + 1] = 'H';
					break;
				case 'j':in_string[i + 1] = 'J';
					break;
				case 'k':in_string[i + 1] = 'K';
					break;
				case 'l':in_string[i + 1] = 'L';
					break;
				case 'z':in_string[i + 1] = 'Z';
					break;
				case 'x':in_string[i + 1] = 'X';
					break;
				case 'c':in_string[i + 1] = 'C';
					break;
				case 'v':in_string[i + 1] = 'V';
					break;
				case 'b':in_string[i + 1] = 'B';
					break;
				case 'n':in_string[i + 1] = 'N';
					break;
				case 'm':in_string[i + 1] = 'M';
					break;
				}
				for (int j = i; j < 999; j++)
				{
					in_string[j] = in_string[j + 1];
				}
				i--;
			}
		}
	}
	printf("%s", in_string);
	getchar(); getchar();
	return 0;
}
