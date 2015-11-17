/*************************************************************************
	> File Name: find.c
	> Author: xgli0807
	> Mail: xgli0807@Gmail.com 
	> Created Time: 2015年09月28日 星期一 21时17分37秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>

int main(){
	FILE *pFile,*tFile,*trueFile,*falseFile,*falseFile1;
	char string[500];
	char str[500];
	char copy[500];
	char copy1[500];
	//pFile = fopen("/home/li/Downloads/tac_kbp_2015_tedl_training_gold_standard_entity_mentions_v1.1.tab","r");
	tFile = fopen("/home/li/Downloads/result.txt","r");
	trueFile = fopen("/home/li/Downloads/true","w");
	falseFile = fopen("/home/li/Downloads/false","w");
	falseFile1 = fopen("/home/li/Downloads/false1","w");
	if(tFile == NULL && trueFile == NULL && falseFile == NULL && falseFile1 == NULL){
		printf("file not open\n");
	}
	else{
		while(fgets(string,200,tFile) != NULL){
			strcpy(copy,string);
			char delims[] = "\t";
			char *p = NULL;
			char *q = NULL;
			char *p1 = NULL;
			char *q1 = NULL;
			char s[500];
			char t[500];
			char *s1;
			p = strtok(string,delims);
			int i = 2;
			while(i--){
				p = strtok(NULL,delims);
			}
			s1 = p;
			while(strlen(p) < 20){
				p = strtok(NULL,delims);
			}
			p1 = strtok(NULL,delims);
			pFile = fopen("/home/li/Downloads/tac_kbp_2015_tedl_training_gold_standard_entity_mentions_v1.1.tab","r");
			if(pFile == NULL){
				perror("Error opening file");
			}
			while(fgets(str,200,pFile) != NULL){
				strcpy(copy1,str);
				if(strstr(str,s1) != NULL){
					q = strtok(str,delims);
					i = 2;
					while(i--){
						q = strtok(NULL,delims);
					}
					while(strlen(q) < 20){
						q = strtok(NULL,delims);
					}
					q1 = strtok(NULL,delims);
				   if(strcmp(p,q) == 0){
						if(p1[0] == 'N' && q1[0] == 'N'){
							fprintf(trueFile,"%s\n",copy);
							break;
						}
					   if(strstr(p1,q1) != NULL){
							fprintf(trueFile,"%s\n",copy);
							break;
					   }
						else{
								fprintf(falseFile1,"%s\n",copy);
								fprintf(falseFile1,"%s\n",copy1);
								break;
						}
				   }
				   else{
						fprintf(falseFile,"%s\n",copy);
						fprintf(falseFile,"%s\n",copy1);
					   printf("false\n");
					   break;
				   }
				}	
			}
			fclose(pFile);
		}
		fclose(tFile);
		fclose(falseFile);
		fclose(trueFile);
	}

	
}
