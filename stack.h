#ifndef __STACK_H__
#define __STACK_H__
typedef struct _list_node_ list_node;
struct _list_node_{
	int data;
	list_node* link;
};

list_node* push(list_node* top, int data);
list_node* pop(list_node* top, int data);
#endif