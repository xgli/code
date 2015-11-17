/*************************************************************************
	> File Name: work1.c
	> Author: xgli0807
	> Mail: xgli0807@Gmail.com 
	> Created Time: 2015年09月16日 星期三 10时35分53秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main(){
	FILE *fp,*fpw1,*fpw2,*fpw3,*fpw4;
	fp = fopen("/home/li/Downloads/false_link","r");
	fpw1 = fopen("/home/li/code/case1","w");
	fpw2 = fopen("/home/li/code/case2","w");
	fpw3 = fopen("/home/li/code/case3","w");
	fpw4 = fopen("/home/li/code/case4","w");
	char s0[100];
	char s1[100];
	char temp[100];
	char s2[100];
	char s3[100];
	char s[500];

	while(fscanf(fp,"%s",s0)!= EOF){
		memset(s,0,sizeof(s));
		strcat(s,s0);
		strcat(s,"  ");
		fscanf(fp,"%s",s1);
		strcat(s,s1);
		strcat(s,"  ");
		fscanf(fp,"%s",temp);
		strcat(s,temp);
		strcat(s,"  ");
		while(strlen(temp) < 30){
			fscanf(fp,"%s",temp);
			strcat(s,temp);
			strcat(s," ");
		}
		fscanf(fp,"%s",s2);
		strcat(s,s2);
		strcat(s,"  ");
		fscanf(fp,"%s",s3);
		strcat(s,s3);
		strcat(s,"  ");
		strcat(s,"\n");

		if(strcmp(s0,s2)!=0){
			fprintf(fpw1,"%s",s);	
		}
		else{
			if(s1[0]=='N'){
				fprintf(fpw2,"%s",s);	
			}
			else if(s3[0]=='N'){
				fprintf(fpw3,"%s",s);
			}
			else{
				fprintf(fpw4,"%s",s);
			}
			
		
		}
		//printf("s0:%s   s1:%s   s2:%s    s3:%s   %d   %d\n",s0,s1,s2,s3,strcmp(s0,s2),strcmp(s1,s3));
		
	//	printf("%s",s);	
	
	
	//	fprintf(fpw,"s0:%s   s1:%s   s2:%s    s3:%s   %d   %d\n",s0,s1,s2,s3,strcmp(s0,s2),strcmp(s1,s3));
	//	fprintf(fpw,"%s",s);	
	}
	fclose(fp);
	fclose(fpw1);
	fclose(fpw2);
	fclose(fpw3);
	fclose(fpw4);

}
