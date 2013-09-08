#pragma once
#include "common_data.h"

//Reverse a linked list. 
void algo_11_reverse_slist_iter(SList **);
SList * algo_11_reverse_slist_rec(SList *);

void algo_11()
{
	printf("algo_11 test: reverse liked list\n");
	
    SList * list = new SList(0);
    fill_slist(list, 33);
    print_slist(list);
    algo_11_reverse_slist_iter(&list);
    print_slist(list);

    list = algo_11_reverse_slist_rec(list);
    print_slist(list);
}

void algo_11_reverse_slist_iter(SList ** list)
{
    if ( !(*list) || !(*list)->next)
        return;
    SList * t = 0; 
    SList * rev = 0;
    while (*list)
    {
        t = *list;
        (*list) = (*list)->next;
        t->next = rev;
        rev = t; 
    }
    *list = rev;
}

SList * algo_11_reverse_slist_rec(SList *node)
{
    if (!node || !node->next)
        return node;
    SList * t = algo_11_reverse_slist_rec(node->next);
    node->next->next = node;
    node->next = 0;
    return t;
}

