#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include"ch1_basic.h"
#define ITEM_INIT_VAL -9999
#define ITEM_LENS 40
#define ITEM_ELE_LENS 10

int main() {
	connective();
	system("pause");
	return 0;
}

int is_connect(char *path_arrs,int m,int n ,char *str,int arrs_1_index) {
	int flag = 0;
	char(*ptr_arrs)[ITEM_LENS][ITEM_ELE_LENS] = path_arrs;
	printf("\n");
	for (int i = 0;i < arrs_1_index;i++) {
		printf("%s\n",(*ptr_arrs)[i]);
	}
	return flag;
}

/*
	输入一个格式为x-x的表示路径的字符串
*/
char* ret_str() {
	char str_arrs[ITEM_ELE_LENS];
	char* str=NULL;
	int p= ITEM_INIT_VAL;
	int q = ITEM_INIT_VAL;
	char p_str = '\0';
	char q_str = '\0';
	printf("%d %d\n",p,q);
	int ret = scanf("%d-%d", &p, &q);
	if (ret == 2) {
		str = malloc(sizeof(char)*ITEM_ELE_LENS);
		p_str = int_2_char_10(p);
		q_str = int_2_char_10(q);
		str_arrs[0] = p_str;
		str_arrs[1] = '-';
		str_arrs[2] = q_str;
		str_arrs[3] = '\0';
		//char *tmp=strcat(strcat(strcat(str, p_str),'-'), q_str);
		strcpy(str, str_arrs);
	}
	else {
		printf("program stop! scanf input format error! \n");
	}
	return str;
}


int connective() {
	char path_arrs[ITEM_LENS][ITEM_ELE_LENS];
	int arrs_1_index = 0;
	int arrs_2_index = 0;
	int p = ITEM_INIT_VAL;
	int q = ITEM_INIT_VAL;
	int flag = 1;//控制循环结束标记位
	while (flag) {
		//scanf 返回值代表匹配的数据个数
		int ret = scanf("%d-%d", &p, &q);
		if (ret == 2) {
			//0-0代表结束标志
			if (p==0 && q==0) {
				flag = 0;
			}
			else {
				path_arrs[arrs_1_index][arrs_2_index++] = int_2_char_10(p);
				path_arrs[arrs_1_index][arrs_2_index++] = '-';
				path_arrs[arrs_1_index][arrs_2_index++] = int_2_char_10(q);
				path_arrs[arrs_1_index][arrs_2_index] = '\0';
				arrs_2_index = 0;
				arrs_1_index++;
			}
		}
		else {
			flag = 0;
			printf("program stop! scanf input format error! \n");
		}
	}
	for (int i = 0;i <arrs_1_index;i++) {
		printf("%s\n", path_arrs[i]);
		//printf("%s \n", path_arrs[arrs_1_index]);
	}

	/*
	char * str_ret=ret_str();
	printf("%s\n",str_ret);
	is_connect(path_arrs, ITEM_LENS, ITEM_ELE_LENS,str_ret,arrs_1_index);
	*/
	return 0;
}

