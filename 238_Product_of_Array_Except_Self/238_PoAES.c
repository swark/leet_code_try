#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
nums:  [2,2,3,4]
Output: [24,12,8,6]
L=[24,24,12,4]
R=[1,2,6,24]
*/
#define size 5
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int * output=(int*)malloc(sizeof(int)*(numsSize));
    int i=0,temp_l=1;
    *returnSize=numsSize;
    //right
    output[0]=nums[0];
    for(i=1;i<(*returnSize);i++){
        output[i]=output[i-1]*nums[i];
    }
    //left
    for(i=(*returnSize)-1;i>=0;i--){
        if(i==(*returnSize)-1)
            output[i]=output[i-1];
        else if(i==0)
            output[i]=temp_l;
        else{
            output[i]=output[i-1]*temp_l;
            //printf("output[i-1]=%d,temp_l=%d ans=%d\n",output[i-1],temp_l,output[i]);
        }
        temp_l=temp_l*nums[i];

    }
    return output;
}

int main(){
    int nums[size]={1,2,3,4,5};
    int *output;
    int i=0;
    int returnSize=0;
    /*for(i=0;i<10;i++){
        scanf("%d",nums+i);
    }*/
    returnSize=size;
    output=productExceptSelf(nums,size,&returnSize);
    if(output){
        for(i=0;i<returnSize;i++)
            printf("%d ",output[i]);
        free(output);
    }
    return 0;
}