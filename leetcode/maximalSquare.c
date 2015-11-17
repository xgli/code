/*************************************************************************
	> File Name: maximalSquare.c
	> Author: xgli0807
	> Mail: xgli0807@Gmail.com 
	> Created Time: 2015年10月07日 星期三 22时24分08秒
 ************************************************************************/

#include<stdio.h>

int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize){
	int i,j;
	int d[matrixColSize];
	int max = 0;
	
	for(i= 0; i < matrixRowSize; i++){
		for(j = 0; j < matrixColSize; j++){
			if(i == 0 || j == 0){
				d[j] = (int)matrix[i][j] - '0';
				if(d[j] > max){
					max = d[j];
				}
			}
			else{
				if(matrix[i][j] == '1'){
					if(d[j] == d[j-1]){
						d[j] = d[j] + 1;
						if(d[j] > max)
							max = d[j];
					}
					else
						d[j] = 0;
				}
				else
					d[j] = 0;
			}
		}
	}
	return max;
}


main()
{
	char s[1][1];
	s[0][0] = '1';
	maximalSquare(&s[0][0],1,1);

}
