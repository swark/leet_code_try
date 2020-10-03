/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define len_num 10
int combination_10(int k){
    //C(n,k)=n!/(n-k)!(k)!
    //10!=3628800
    int factor=len_num-k,m1=factor,m2=k,ans=0;
    if(k==0||k==len_num){
        return 1;
    }

    while(factor!=1){
        m1=m1*(--factor);
    }
    while(k!=1){
        m2=m2*(--k);
    }

    ans=3628800/(m1*m2);
    return ans;
}

void backtrack(int num, int* returnSize,int current_num,int led_idx,unsigned char temp_time_h,unsigned char temp_time_m,char** output,char* check){
    int i=0;
    char temp_str[7]={0};
    char*format="\"%d:%02d\"";

    if(current_num==num){
        //check format
        if(temp_time_h-'0'>=12||temp_time_m-'0'>=60){
            return;
        }

        snprintf(temp_str,7,format,temp_time_h-'0',temp_time_m-'0');    
        for(i=0;i<(*returnSize);i++){
            if(!strncmp(output[i],temp_str,6)){
                return;
            }
        }

        //put into output
        output[*returnSize]=(char*)malloc(6*sizeof(char));
        snprintf(output[*returnSize],7,format,temp_time_h-'0',temp_time_m-'0');
        (*returnSize)++;
        return;
    }else if(current_num>num){
        return;
    }

    for(i=led_idx;i<len_num;i++){
        if(check[i]!=1){
            check[i]=1; 
            if(i<=3){
                backtrack(num,returnSize,current_num+1,led_idx+1,temp_time_h+(1<<i),temp_time_m,output,check);
            }else{
                backtrack(num,returnSize,current_num+1,led_idx+1,temp_time_h,temp_time_m+(1<<(i-4)),output,check);
            }
            check[i]=0;
        }
    }
}

char ** readBinaryWatch(int num, int* returnSize){
    unsigned char temp_time_h='0';
    unsigned char temp_time_m='0';
    int max_output=combination_10(num);
    char** output=(char**)malloc(max_output*sizeof(char*)*2);
    char check[10]={0};

    *returnSize=0;

    backtrack(num,returnSize,0,0,temp_time_h,temp_time_m,output,check);

    return output;
}
int main(){
    int input=0,i=0;
    int returnSize=0;
    char **output;

    printf("input number of LED:");
    scanf("%d",&input);

    output=readBinaryWatch(input,&returnSize);

    printf("[");
    for(i=0;i<returnSize;i++){
        if(i!=returnSize-1)
            printf("%s,",output[i]);
        else
            printf("%s",output[i]);
    }
    printf("]\n");
    if(output)
        free(output);
    return 0;
}