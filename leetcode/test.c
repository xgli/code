/*************************************************************************
	> File Name: test.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2015年09月16日 星期三 08时42分22秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
	
int numDecodings(char* s) {
	int len = strlen(s);
	if(len == 0){
		return 0;
	}
	if(s[0] == '0'){
		return 0;
	}
	if(len == 1){
		return 1;
	}
	int  d[5000];
	d[0] = 0;
	d[1] = 1;
							
	int i = 1;
	int r;
									
	while(s[i] != '\0'){
		r = (s[i-1] - '0')*10 + (s[i]-'0');
		if(s[i]=='0'){
			if(r == 0){
				return 0;
			}
			if(r < 26){
				d[i+1] = d[i-1] + 1;
			}
			if(r > 26){
				return 0;
			}
		}
		else{
			if(r < 10){
				d[i+1] = d[i];
			}
			else if(r < 27&&r > 10){
				d[i+1] = d[i] + d[i-1] ;
			}
			else{
				d[i+1] = d[i];
			}
																								
		}
		i++;
	}
	return d[i];										
}

int main(){

	char s[100];
	scanf("%s",s);
	printf("%d\n",numDecodings(s));

}


