/*************************************************************************
	> File Name: minPathSum.c
	> Author: xgli0807
	> Mail: xgli0807@Gmail.com 
	> Created Time: 2015年09月28日 星期一 18时45分14秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>

int min(int a, int b)
{
	if(a > b)
		return b;
	else
		return a;
}

int minPathSum(int **grid, int gridRowSize, int gridColSize)
{
	int *d;
	d = (int *)malloc(sizeof(int)*gridColSize);
	
	int i, j;
	for(i = 0; i < gridRowSize; i++){
		for(j = 0; j < gridColSize; j++){
			if(i == 0&&j>0){
				d[j] = d[j-1] + grid[i][j];
			}
			else if(j == 0){
				d[j] = d[j] + grid[i][j];
			}
			else if(j > 0)
				d[j] = min(d[j-1],d[j]) + grid[i][j];
		}
	}
	return d[j-1];
}

int main()
{
	int v[2][3] = {1,2,5,3,2,1};
	printf("%d\n",minPathSum((int**)v,2,3));
}


