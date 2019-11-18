#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
int pre_order_sum_BST(struct TreeNode* root, int L, int R){
	int sum=0;
	if(root){
		if((root->val)>=L && (root->val)<=R){
			sum=sum+pre_order_sum_BST(root->left,L,R);
			sum=sum+pre_order_sum_BST(root->right,L,R);
			sum=sum+root->val;
			//return root->val;
		}else if((root->val)<L){
			//pre_order_sum_BST(root->left);
			sum=sum+pre_order_sum_BST(root->right,L,R);
			//return 0;
		}else if((root->val)>R){
			sum=sum+pre_order_sum_BST(root->left,L,R);
			//return 0;
		}else{
			printf("WTF\n");
			return 0;
		}
		return sum;
	}else{
		return 0;
	}
}
int rangeSumBST(struct TreeNode* root, int L, int R){
	int sum=0;
	if(root){
		if((root->val)>=L && (root->val)<=R){
			sum=sum+rangeSumBST(root->left,L,R);
			sum=sum+rangeSumBST(root->right,L,R);
			sum=sum+root->val;
			//return root->val;
		}else if((root->val)<L){
			//pre_order_sum_BST(root->left);
			sum=sum+rangeSumBST(root->right,L,R);
			//return 0;
		}else if((root->val)>R){
			sum=sum+rangeSumBST(root->left,L,R);
			//return 0;
		}
		return sum;
	}else{
		return 0;
	}
}
void insert_BST(struct TreeNode** root,struct TreeNode* insert_node){
	struct TreeNode* temp_p,*parent;
	temp_p=*root;
	if(temp_p==NULL){
		*root=insert_node;
	}else{
		while(temp_p!=NULL){
			parent=temp_p;
			if((insert_node->val)<(temp_p->val)){
				temp_p=temp_p->left;
				if(temp_p==NULL){
					parent->left=insert_node;
					break;
				}
			}else{
				temp_p=temp_p->right;
				if(temp_p==NULL){
					parent->right=insert_node;
					break;
				}
			}
		}
	}
}
void pre_order_BST(struct TreeNode* root){
	if(root){
		printf("%d ",root->val);
		pre_order_BST(root->left);
		pre_order_BST(root->right);
	}
}
void in_order_BST(struct TreeNode* root){
	if(root){
		in_order_BST(root->left);
		printf("%d ",root->val);
		in_order_BST(root->right);
	}
}
void print_post_order_BST(struct TreeNode* root){
	if(root){
		//printf("%d ",root->val);
		print_post_order_BST(root->left);
		print_post_order_BST(root->right);
		printf("%d ",root->val);
	}
}
void free_post_order_BST(struct TreeNode* root){
	if(root){
		//printf("%d ",root->val);
		free_post_order_BST(root->left);
		free_post_order_BST(root->right);
		free(root);
	}
}
void print_BST(struct TreeNode* root){
	
	struct TreeNode* temp_p=root;
	if(temp_p==NULL){
		printf("The BST is empty\n");
	}else{
		printf("Pre-order BST:");
		pre_order_BST(root);
		printf("\nIn-order BST: ");
		in_order_BST(root);
		printf("\nPost-order BST:");
		print_post_order_BST(root);
		printf("\n");
	}
}

int main(int argc, char *argv[]){
	//insert tree
	int new_val=0,lower_bound=0,upper_bound=0,ret=0;
	struct TreeNode* temp_p=NULL, *root=NULL;
	if(argc==3){
		lower_bound=atoi(argv[1]);
		upper_bound=atoi(argv[2]);
	}else{
		printf("bad input\n");
		return 0;
	}
	while(new_val!=-1){
		scanf("%d",&new_val);
		if(new_val==-1)
			break;
		temp_p=(struct TreeNode*)malloc(1*sizeof(struct TreeNode));
		if(temp_p){
			temp_p->val=new_val;
			temp_p->left=NULL;
			temp_p->right=NULL;
			insert_BST(&root,temp_p);
		}
	}
	print_BST(root);
	//ret=pre_order_sum_BST(root,lower_bound,upper_bound);
	ret=rangeSumBST(root,lower_bound,upper_bound);
	printf("ret=%d\n",ret);
	free_post_order_BST(root);
	//calculate the sum of tree in range
	
	return 0;
}