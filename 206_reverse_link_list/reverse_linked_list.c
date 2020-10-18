#include <stdlib.h>
#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode_t {
    int val;
     struct ListNode_t *next;
 }ListNode;

void printList(ListNode* head){
    ListNode* ptr=head;
    while(ptr!=NULL){
        printf(" val=%d ->",ptr->val);
        ptr=ptr->next;
    }
    printf("\n");
}

ListNode* reverseList(ListNode* head){
    ListNode * prev=NULL,*cur=head;
    ListNode * temp=NULL;
    while(cur!=NULL){
        temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
    }
    return prev;
}

int main(){
    int i=0;
    ListNode * head=NULL;
    ListNode * temp=NULL,*ptr=NULL;
    //char test=0;
    //unsigned char t2=0;
    for(i=0;i<6;i++){
        temp=(ListNode*)malloc(sizeof(ListNode));
        temp->val=i;
        temp->next=NULL;
        if(head==NULL){
            head=temp;
            ptr=head;
        }else{
            ptr->next=temp;
            ptr=ptr->next;
        }
    }
    printList(head);
    head=reverseList(head);
    printList(head);
    /*for(t2=0;t2<256;t2++){
        if(t2%10==0)
            printf("\n");
        printf("%d,",t2);
    }*/
    return 0;
}