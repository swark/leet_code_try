#ifndef __STACK_H__
#define __STACK_H__
typedef struct _list_node_ list_node;
typedef struct _list_node_{
	int data;
	list_node* link;
}list_node;

list_node* push_stack(list_node* top, int data);
list_node* pop_stack(list_node* top);
#endif