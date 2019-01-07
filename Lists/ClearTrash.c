int ForCTS(char c, char from, char to, int isNotTrash)
{
	for (char i = from; i <= to; i++)
	{
		if (c == i)
			isNotTrash++;
	}
	return isNotTrash;
}
char ClearTrashSymbol(char c)
{
	int isNotTrash = 0;

	isNotTrash = ForCTS(c, 'a', 'z', isNotTrash);
	isNotTrash = ForCTS(c, 'A', 'Z', isNotTrash);
	isNotTrash = ForCTS(c, 'à', 'ÿ', isNotTrash);
	isNotTrash = ForCTS(c, 'À', 'ß', isNotTrash);
	isNotTrash = ForCTS(c, '0', '9', isNotTrash);
	if (isNotTrash > 0)
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
