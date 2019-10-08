#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int numJewelsInStones(char * J, char * S){
	int ans=0,i=0;
	int hash_table[58]={0};
	for(i=0;i<strlen(J);i++){
		hash_table[*(J+i)-65]=1;
	}
	for(i=0;i<strlen(S);i++){
		if(hash_table[*(S+i)-65]==1)
			ans++;
	}
	return ans;
}
int main(int argc, char *argv[]){
	int ans=0;
	if(argc != 3){
		printf("Bad input\n");
		return 0;
	}else{
		printf("Get %s %s\n",argv[1],argv[2]);
	}
	ans=numJewelsInStones(argv[1],argv[2]);
	printf("ans=%d\n",ans);
	return 0;
}