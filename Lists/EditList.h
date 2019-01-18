#pragma once
struct editIP EditIP(int numPart);
void EditElement(struct list *head, int *lenghtTypesPC, struct TypePC *typesPC, int lenghtLists);
void EditTypePC(int *lenghtTypesPC, int lenghtLists, struct TypePC *typesPC, struct list *head);
struct list * AllEditTPC(struct list *head, struct TypePC *typesPC, int lenghtLists);