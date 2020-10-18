#include <stdlib.h>
#include <stdio.h>

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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
    ListNode *head=NULL,*ret,*ptr_l1=l1,*ptr_l2=l2;
    while (ptr_l1!=NULL&&ptr_l2!=NULL)
    {
        if(head==NULL){
            if(ptr_l1->val<=ptr_l2->val){
                ret=head=ptr_l1;
                ptr_l1=ptr_l1->next;
            }else{
                ret=head=ptr_l2;
                ptr_l2=ptr_l2->next;
            }
        }
        if(ptr_l1->val<=ptr_l2->val){
            head->next=ptr_l1;
            ptr_l1=ptr_l1->next;
        }else{
            head->next=ptr_l2;
            ptr_l2=ptr_l2->next;
        }
        head=head->next;
    }
    if(ptr_l1!=NULL){
        head->next=ptr_l1;
    }else if(ptr_l2!=NULL){
        head->next=ptr_l2;
    }
    
    return ret;
}
int main(){
    int i=0;
    ListNode * head=NULL,*head2=NULL;
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

    for(i=0;i<6;i++){
        temp=(ListNode*)malloc(sizeof(ListNode));
        temp->val=i;
        temp->next=NULL;
        if(head2==NULL){
            head2=temp;
            ptr=head2;
        }else{
            ptr->next=temp;
            ptr=ptr->next;
        }
    }

    printList(head);
    printList(head2);
    temp=mergeTwoLists(head,head2);
    printList(head);
    printList(head2);
    printList(temp);
    return 0;
}