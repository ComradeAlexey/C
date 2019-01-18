#include "FileWork.h"

void WriteFile(struct list * head, int lenghtLists)
{
	FILE *S1, *S2;
	struct list *select = head;
	S1 = fopen("Structs.txt", "w");
	for (int i = 0; i < lenghtLists; i++)
	{
		fprintf(S1, "id(%d)|name_user:", i);
		for (int j = 0; j < 10; j++)
		{
			if (select->_db.name_user[j] != '\0' & select->_db.name_user[j] != ' ')
			{
				fprintf(S1, "%c",select->_db.name_user[j]);
			}
			else
			{
				j = 10;
				fprintf(S1, ";");
			}
		}

		fprintf(S1, "\nid(%d)|surname_user:", i);
		for (int j = 0; j < 10; j++)
		{
			if (select->_db.surname_user[j] != '\0' & select->_db.surname_user[j] != ' ')
			{
				fprintf(S1, "%c", select->_db.surname_user[j]);
			}
			else
			{
				j = 10;
				fprintf(S1, ";");
			}
		}

		fprintf(S1, "\nid(%d)|name_pc:", i);
		for (int j = 0; j < 10; j++)
		{
			if (select->_db.name_pc[j] != '\0' & select->_db.name_pc[j] != ' ')
			{
				fprintf(S1, "%c", select->_db.name_pc[j]);
			}
			else
			{
				j = 10;
				fprintf(S1, ";");
			}
		}

		fprintf(S1, "\nid(%d)|groupe_user:", i);
		for (int j = 0; j < 5; j++)
		{
			if (select->_db.groupe_user[j] != '\0' & select->_db.groupe_user[j] != ' ')
			{
				fprintf(S1, "%c", select->_db.groupe_user[j]);
			}
			else
			{
				j = 10;
				fprintf(S1, ";");
			}
		}
		fprintf(S1, "\nid(%d)|IP_user:%d.%d.%d.%d;", i, select->_db._ip.oneCell, select->_db._ip.twoCell, select->_db._ip.threeCell, select->_db._ip.fourCell);
		fprintf(S1, "\nid(%d)|nameType:%s,%d;\n",i,select->_db.typePC.nameType, select->_db.typePC.typeNum);

		select = select->next;
	}
	fclose(S1);
	/*S1 = fopen("S1.txt", "r");
	S2 = fopen("S2.txt", "w");
	fscanf(S1, "%d", &y);*/
	//y += 3;
	//fclose(S1);
	//fprintf(S2, "%d\n", y);
	//fclose(S2);
}
