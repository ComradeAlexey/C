#pragma once
struct list * init(struct db a, int *lenghtLists);
struct db dbEnterData(int *lenghtTypesPC, struct  TypePC *typesPC);
struct list * addelem(struct list *head, int *lenghtLists, int *lenghtTypesPC, struct  TypePC *typesPC);
struct list * addElemToEnd(struct list *head, int *lenghtTypesPC, struct  TypePC *typesPC, int *lenghtLists);