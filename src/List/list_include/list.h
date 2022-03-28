#ifndef LIST_H
#define LIST_H


#include <stdio.h>
#include <stdlib.h>
#include <cstddef>
#include <assert.h>
#include <string.h>
#include <time.h>


#define SPECIFICATOR "zu"

struct item_t
{
    char    mas[16];
    size_t  size;
};


struct node
{
    item_t  data;
    node*   next;
    node*   prev;
};


struct list
{
    node*   head;
    node*   tail;
    size_t  size;
};


void    list_ctor(list *const p_list);

void    list_dtor(list *const p_list);

void    list_dump(const list* const p_list);

void    list_insert_tail(list* const p_list, const item_t item);

void    list_insert_head(list* const p_list, const item_t item);

void    list_delete_tail(list* const p_list, item_t* p_item);

void    list_delete_head(list* const p_list, item_t* p_item);

void    list_delete_node(list* const p_list, node* const p_node);

node*   list_data_search(list* const p_list, const item_t item);


#endif