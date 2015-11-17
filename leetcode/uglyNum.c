/*************************************************************************
	> File Name: uglyNum.c
	> Author: xgli0807
	> Mail: xgli0807@Gmail.com 
	> Created Time: 2015年09月26日 星期六 17时44分48秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>

int min(int a,int b,int c){
	int min = a;
	if(min > b)
		min = b;
	if(min > c)
		min = c;
	return min;
}

int nthUglyNumber(int n){
	int *list;
	list = (int *)malloc(sizeof(int)*n);
	list[0] = 1;
	
	int a, b, c;
	a = b = c = 0;
	int	lista = list[a]*2;
	int listb = list[b]*3;
	int	listc = list[c]*5;
	
	int i = 1;
	int temp;
	for(i = 1; i < n; i++){
		temp = min(lista, listb, listc);
		list[i] = temp;
		if(temp == lista){
			lista = list[++a]*2;
		}
		if(temp == listb){
			listb = list[++b]*3;
		}
		if(temp == listc){
			listc = list[++c]*5;
		}
	}
	return list[i-1];

}


int main(){
	int a;
	scanf("%d",&a);
	printf("%d",nthUglyNumber(a));
}
