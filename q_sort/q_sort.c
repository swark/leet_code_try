#include <stdio.h>
void swap(int* ary,int i,int j){
    printf("\n-----B Swap ary[%d]=%d ary[%d]=%d-----\n",i,ary[i],j,ary[j]);
    ary[i]=ary[i]^ary[j];
    ary[j]=ary[i]^ary[j];
    ary[i]=ary[i]^ary[j];
    printf("\n-----A Swap ary[i]=%d ary[j]=%d-----\n",ary[i],ary[j]);
}
void quick_sort(int* ary,int front,int end){
    int p=ary[end];
    int i=front,j=end-1,k=0;
    if(front<end){  
        while(i<j){
            while(ary[i]<p){
                i=i+1;
            }
            while(ary[j]>p){
                j=j-1;
            }
            if(i<j){
                swap(ary,i,j);
                /*printf("\n-----phsa %d-----\n",i);
                for(k=0;k<9;k++)
                    printf("%d,",ary[k]);*/
            }
        }
        swap(ary,i,end);
        printf("\n\n");
        for(k=0;k<9;k++)
            printf("%d,",ary[k]);
        printf("\ni=%d j=%d",i,j);
        quick_sort(ary,front,i-1);//left
        quick_sort(ary,i+1,end);//right
    }
}

int main(){
    int ary[9] = {9, 4, 1, 6, 7, 5, 8, 2, 5};
    int  i=0;
    quick_sort(ary,0,8);
    printf("\n\n");
    for(i=0;i<9;i++)
        printf("%d,",ary[i]);
    return 0;
}