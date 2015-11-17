/*************************************************************************
	> File Name: kmp.c
	> Author: xgli0807
	> Mail: xgli0807@Gmail.com 
	> Created Time: 2015年09月25日 星期五 19时23分03秒
 ************************************************************************/

#include<stdio.h>


int next(const char *pattern, int len, unsigned int *next)
{
	int i = 1, j = 0;
	next[1] = 0;
	
	while(i <= len){
		if(j == 0 || pattern[i-1] == pattern[j-1]){
			i++;
			j++;
			next[i] = j;
		} else {
			j = next[j];
		}
	
	}
	
}

int kmp(char *t, char *p, int next[],int len1, int len2)
{
	int i = 0, j = 0;
	while(i < len1 && j < len2){
		if(j == 0 || t[i] == p[i]){
			i++;
			j++;
		} else {
			j = next[j];
		}
	}
	if(j >= len2) return i - len2;
	return -1;
}

