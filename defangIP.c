#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * defangIPaddr_snprintf(char * address){
	int size=strlen(address)+7;
	char *ans=malloc(sizeof(char)*size);
	while(address && *address!='\r' && *address!='\n' && *address!='\0'){
		if(*address=='.'){
			snprintf(ans+strlen(ans), size-strlen(ans), "%s", "[.]");
		}else{
			snprintf(ans+strlen(ans), size-strlen(ans), "%c", *address);
		}
		address++;
	}
	ans[size]='\0';
	return ans;
}
char * defangIPaddr(char * address){
	int size=strlen(address)+7,i=0;
	char *ans=malloc(sizeof(char)*size);
	while(address && *address!='\r' && *address!='\n' && *address!='\0'){   
		if(*address=='.'){
			*(ans+i++)= '['; 
			*(ans+i++)= '.'; 
			*(ans+i++)= ']'; 
		}else{
			*(ans+i++)= *address; 
		}
		address++;
	}
	*(ans+i)= '\0'; 
	return ans;
}
int main(){
	char str[17];
	char *ans;
	do{
		printf("#");
		scanf("%s",str);
		if(!strcmp(str,"end"))
			break;
		ans=defangIPaddr(str);
		printf("ans=%s\n",ans);
	}while(0);
	return 0;
}
