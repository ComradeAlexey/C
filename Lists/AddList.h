#pragma once
struct list * init(struct db a, int *lenghtLists);
void AddInListTypePC(int *lenghtTypesPC, struct  TypePC *typesPC);
struct addIP AddPartIP(int numPart);
int AddIP(int numPart);
char *AddString(char *name, int lenghtString);
struct db dbEnterData(int *lenghtTypesPC, struct  TypePC *typesPC);
void addelem(struct list *head, int *lenghtLists, int *lenghtTypesPC, struct  TypePC *typesPC);
void addElemToEnd(struct list *head, int *lenghtTypesPC, struct  TypePC *typesPC, int *lenghtLists);