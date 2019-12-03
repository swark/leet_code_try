#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

list_node* push(list_node* top, int data)
{
	list_node* new_entry=(list_node*)malloc(1*sizeof(list_node));
	new_entry->data=data;
	if(top){
		new_entry->link=top;
	}else{
		new_entry->link=NULL;
	}
	top=new_entry;
	return top;
}

list_node* pop(list_node* top, int data)
{
	return NULL;
}

void print_stack(list_node* top)
{
	int idx=0;
	list_node* p=top;
	if(p){
		printf("%d: %d\n",idx++,p->data);
		p=p->link;
	}
}


int main(int argc, char *argv[]){
	//insert tree
	int new_val=0;
	list_node* top=NULL;
	while(new_val!=-1){
		scanf("%d",&new_val);
		if(new_val==-1){
			print_stack(top);
			break;
		}
		push(top,new_val);
	}

	
	return 0;
}