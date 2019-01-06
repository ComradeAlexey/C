#pragma once
struct list * Swap(struct list *first, struct list *second, struct list *head);
int BoolReturnNameUser(struct list *p);
int BoolReturnNameTypePC(struct list *p);
int BoolReturnSurnameUser(struct list *p);
int BoolReturnGroupeUser(struct list *p);
int BoolReturnNamePC(struct list *p);
struct list * SwapInAscendingSort(struct list *p, struct list *head, int *numSwap, int typeSort);
struct list * AscendingSort(struct list *head, int typeSort, int *lenghtLists);