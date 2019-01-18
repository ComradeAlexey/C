#pragma once
void DeletElemAfter(struct list *lst, int *lenghtLists);
void DeleteEndElement(struct list *root, int *lenghtLists);
struct list * DeleteHead(struct list *root, int *lenghtLists); 
void DeleteAllTypesPC(struct TypePC *tpc, int *lenghtTypesPC);
struct list * DeleteTypePC(struct list *head, struct TypePC *typesPC, int * lenghtTypesPC, int *lenghtLists);