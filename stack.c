#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

list_node* push_stack(list_node* top, int data)
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

list_node* pop_stack(list_node* top)
{
	list_node* poped=top;
	top=top->link;
	printf("pop out: %d\n",poped->data);
	free(poped);
	return top;
}

void print_stack(list_node* top)
{
	int idx=0;
	list_node* p=top;
	while(p){
		printf("%d: %d\n",idx++,p->data);
		p=p->link;
	}
}

void relese_stack(list_node* top)
{
	list_node* p=top;
	printf("-----start free stack-----\n");
	while(p){
		top=top->link;
		free(p);
		p=top;
	}
	printf("-----end free stack-----\n");
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
		top=push_stack(top,new_val);
	}	
	/*while(top){
		top=pop_stack(top);
	}*/
	relese_stack(top);

	
	return 0;
}