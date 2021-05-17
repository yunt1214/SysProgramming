#include <stdio.h>
#include <stdlib.h>
int main(){

	char c=0;
	while(1){
	scanf(" %c",&c);

	if(c=='0')break;
	if(c>=65&&c<=90){
	printf("입력한 %c의 소문자는 %c\n",c,c+32);
	}
	if(c>97&&c<=122){
	printf("입력한 %c의 대문자는 %c\n",c,c-32);
	}
	}
	exit(0);	
}
