/*************************************************************************
	> File Name: house.c
	> Author: xgli0807
	> Mail: xgli0807@Gmail.com 
	> Created Time: 2015年09月23日 星期三 21时21分18秒
 ************************************************************************/

#include<stdio.h>

int rob(int* nums, int numsSize){
	int d[numsSize];
	int i;
	if(numsSize == 0){
		return 0;
	}
	if(numsSize == 1){
		return nums[0];
	}
	if(numsSize == 2){
		if(nums[0] > nums[1])
			return nums[0];
		else
			return nums[1];
	}
	if(numsSize == 3){
		if(nums[1] > nums[0] + nums[2])
			return nums[1];
		else
			return nums[0]+nums[2];
	}

	d[0] = nums[0];
	if(nums[0] > nums[1])
		d[1] = nums[0];
	else
		d[1] = nums[1];

	if(nums[1] > nums[0] + nums[2])
		d[2] = nums[1];
	else
		d[2] = nums[0] + nums[2];
	
	for(i = 3; i < numsSize; i++){
		if(d[i-2] > d[i-3])
			d[i] = d[i-2] + nums[i];
		else
			d[i] = d[i-3] + nums[i];
	}
	if(d[i-1] > d[i-2])
		return d[i-1];
	else
		return d[i-2];
}

int main(){
	int v[100];
	int i = 0;
	while(scanf("%d",&v[i]) == 1){
		i++;
	}
	printf("%d\n",rob(v,i)); // rob(v,i);
		

}
