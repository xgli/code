/*************************************************************************
	> File Name: isUgly.c
	> Author: xgli0807
	> Mail: xgli0807@Gmail.com 
	> Created Time: 2015年09月26日 星期六 10时11分18秒
 ************************************************************************/

#include<stdio.h>

bool isUgly(int num){
	while(num % 5 == 0){
		num = num / 5;
	}
	while(num % 3 == 0){
		num = num / 3;
	}
	while(num % 2 == 0){
		num = num / 2;
	}
	if(num == 1)
		return true;
	else
		return false;
}

int main()
{
	int a;
	scanf("%d",&a);
	printf("%d\n",isUgly(a)?1:0);
}
