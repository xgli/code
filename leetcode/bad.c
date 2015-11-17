/*************************************************************************
	> File Name: bad.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2015年09月15日 星期二 20时49分45秒
 ************************************************************************/

#include<stdio.h>
int main()
{
	int low  = 0;
	int high = n;
	while(low < high){
		i = (low + high) / 2;
		if(isBadVersion(i)){
			high = i-1;
		}
		else{
			low = i;
		}
	}
	return high;
}
