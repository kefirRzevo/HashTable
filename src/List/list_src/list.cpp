#include "../list_include/list.h"


void list_ctor(list *const p_list)
{
    assert(p_list);

    p_list->size = 0;
    p_list->head = nullptr;
    p_list->tail = nullptr;
} 


void list_dtor(list *const p_list)
{
    assert(p_list);   

    node* p_node = p_list->tail;
    for(size_t i = 0; i < p_list->size; i++)
    {
        node* new_node = p_node;
        p_node = p_node->next;
        free(new_node);
    }

    p_list->size = 0;
    p_list->tail = nullptr;
    p_list->head = nullptr;
}


void list_insert_tail(list* const p_list, const item_t item)
{
    assert(p_list);

    node* elem = (node* ) calloc(1, sizeof(node) );
    assert(elem);

    elem->prev = nullptr;
    elem->next = p_list->tail;
    elem->data = item;

    if(p_list->tail != nullptr)
    {
        p_list->tail->prev = elem;
    }
    else
    {
        p_list->head = elem; 
    }

    p_list->tail = elem;
    p_list->size++;
}


void list_insert_head(list* const p_list, const item_t item)
{
    assert(p_list);

    node* elem = (node* ) calloc(1, sizeof(node) );
    assert(elem);

    elem->prev = p_list->head;
    elem->next = nullptr;
    elem->data = item;

    if(p_list->head != nullptr)
    {
        p_list->head->next = elem;
    }
    else
    {
        p_list->tail = elem; 
    }

    p_list->head = elem;
    p_list->size++;
}


void list_delete_tail(list* const p_list, item_t* p_item)
{
    assert(p_list);

    if(p_list->size == 0)
    {
        printf("List is empty. Be careful.\n");
        return;
    }

    node* elem = p_list->tail;
    *p_item    = p_list->tail->data;

    if(p_list->tail->next != nullptr)
    {
        p_list->tail->next->prev = nullptr;
        p_list->tail = p_list->tail->next;
    }
    else
    {
        p_list->head = nullptr;
        p_list->tail = nullptr;
    }

    free(elem);
    p_list->size--;
}


void list_delete_head(list* const p_list, item_t* p_item)
{
    assert(p_list);

    if(p_list->size == 0)
    {
        printf("List is empty. Be careful.\n");
        return;
    }

    node* elem = p_list->tail;
    *p_item    = p_list->tail->data;

    if(p_list->head->prev != nullptr)
    {
        p_list->head->prev->next = nullptr;
        p_list->head = p_list->head->prev;
    }
    else
    {
        p_list->head = nullptr;
        p_list->tail = nullptr;
    }

    free(elem);
    p_list->size--;
}


void list_delete_node(list* const p_list, node* const p_node)
{
    assert(p_list);
    assert(p_node);

    if(p_list->size == 0)
    {
        printf("List is empty. Be careful.\n");
        return;
    }

    if(p_node->prev != nullptr && p_node->next != nullptr)
    {
        p_node->next->prev = p_node->prev;
        p_node->prev->next = p_node->next;
    }
    else if(p_node->prev == nullptr)
    {
        p_node->next->prev = p_node->prev;
    }
    else
    {
        p_node->prev->next = p_node->next;
    }

    free(p_node);
    p_list->size--;
}


node* list_data_search(list* const p_list, const item_t item)
{
    assert(p_list);

    node* temp = p_list->tail;
    
    while(temp != nullptr)
    {
        if(!strcmp(item.mas, temp->data.mas))
            break;

        temp = temp->next;
    }

    return temp;
}

