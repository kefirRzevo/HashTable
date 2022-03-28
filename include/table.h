#ifndef TABLE_H
#define TABLE_H


#include <stdio.h>
#include <stdlib.h>
#include <cstddef>
#include <assert.h>
#include <string.h>
#include <time.h>
#include "../src/List/list_include/list.h"


typedef size_t hash_t;


struct hash_table
{
    list*   table;
    size_t  size;
};


void table_ctor(hash_table* p_hash_table, size_t table_size);

void table_dtor(hash_table* p_hash_table);

void add_item(hash_table* p_hash_table, item_t* item);

void delete_item(hash_table* p_hash_table, item_t* item);

void table_search(hash_table* p_hash_table, item_t* item);


#endif