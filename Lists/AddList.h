#pragma once
struct list * init(struct db a, int *lenghtLists);
struct DBAndTPC dbEnterData(int *lenghtTypesPC, struct  TypePC *typesPC);
struct ListAndTypePC addelem(struct list *head, int *lenghtLists, int *lenghtTypesPC, struct  TypePC *typesPC);
struct ListAndTypePC addElemToEnd(struct list *head, int *lenghtTypesPC, struct  TypePC *typesPC, int *lenghtLists);