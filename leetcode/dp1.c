/*************************************************************************
	> File Name: dp1.c
	> Author: xgli0807
	> Mail: xgli0807@Gmail.com 
	> Created Time: 2015年09月16日 星期三 22时25分15秒
 ************************************************************************/

#include<stdio.h>
int main(){
	
	int n;
	int v[n];
	
	int max = 0;
	int temp = 0;
	for(i = 0; i < n; i++){
		temp = temp + v[i];
		if(temp > max){
			max = temp;
		}
		if(temp < 0){
			temp = 0;
		
	}


}
