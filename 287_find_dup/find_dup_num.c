#include <stdio.h>
#include <stdlib.h>
#define size 5
typedef struct node{
    int value;
    struct node *rlink;
    struct node *llink;
}Node;

void pre_order_BST(Node* root){
	if(root){
		printf("%d ",root->value);
		pre_order_BST(root->llink);
		pre_order_BST(root->rlink);
	}
}

int BT_comp_and_insert(Node* root,int value){
    Node *temp;
    if(value==root->value){
        //printf("FINNNND %d\n",value);
        return value;
    }else if(value>root->value){
        if(root->rlink==NULL){
            temp=(Node*)malloc(sizeof(Node));
            temp->value=value;
            temp->llink=NULL;
            temp->rlink=NULL;
            root->rlink=temp;
            return 0;
        }else{
           return BT_comp_and_insert(root->rlink,value);
        }
    }else{
        if(root->llink==NULL){
            temp=(Node*)malloc(sizeof(Node));
            temp->value=value;
            temp->llink=NULL;
            temp->rlink=NULL;
            root->llink=temp;
            return 0;
        }else{
           return BT_comp_and_insert(root->llink,value);
        }
    }
}

int findDuplicate(int* nums, int numsSize){
    Node root;
    int i=0;
    int ret=0;
    if(numsSize>=2){
        root.value=nums[0];
        root.llink=NULL;
        root.rlink=NULL;
        for(i=1;i<numsSize;i++){
            /*printf("print tree\n");
            pre_order_BST(&root);
            printf("print tree END\n\n");*/
            ret=BT_comp_and_insert(&root,nums[i]);
            if(ret!=0)
                break;
        }
    }else{
       return nums[0];
    }
    return ret;
}

int main(){
    int nums[size]={1,3,4,2,3};
    //int nums[size]={13,46,8,11,20,17,40,13,13,13,14,1,13,36,48,41,13,13,13,13,45,13,28,42,13,10,15,22,13,13,13,13,23,9,6,13,47,49,16,13,13,39,35,13,32,29,13,25,30,13};
    int i=0;
    for(i=0;i<size;i++){
        //printf("%d ",nums[i]);
    }
    printf("\nfind:%d\n",findDuplicate(nums,size));
    return 0;

}