#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ch1_basic.h"
#include"string_utils.h"
#include"error_handle.h"

int main() {
	connective();
	system("pause");
	return 0;
}

int is_connect(char *path_arrs,int arrs_1_index) {
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

//二维数组中的路径去重
int remove_duplicate(char arrs[ITEM_LENS][ITEM_ELE_LENS],int arrs_1_index, int *arrs_1_index_p) {
	//重复的路径数组
	char pds[ITEM_LENS][ITEM_ELE_LENS];
	//重复路径数组的序号
	int index = 0;
	//将二维数组相同的两份 遍历一遍
	for (int i = 0;i < arrs_1_index;i++) {
		for (int j = 0;j < arrs_1_index;j++) {
			//如果第i行遍历数组，并且遍历的一维序号不是i，则进行处理
			if (strcmp(arrs[i], arrs[j]) == 0 && i!=j) {
				int k = 0;
				//遍历存储的重复的数字对数组
				for (k = 0;k < index;k++) {
					if ( (pds[k][0]==arrs[i][0] && pds[k][2]==arrs[i][2]) || (pds[k][0]==arrs[i][2] && pds[k][2]==arrs[i][0]) ) {
						break;
					}
				}
				if (k == index) {
					pds[index][0] = arrs[i][0];
					pds[index][1] = '-';
					pds[index][2] = arrs[i][2];
					pds[index][3] = '\0';
					index++;
				}
			}
		}
	}
	remove_duplicate_arrs(arrs, arrs_1_index,pds,index, arrs_1_index_p);
}


//比对2个数组，去掉重复的二维数组字符串 
//arrs1 字符串数组,       arrs_1_index 字符串数组结束索引, 
//arrs2 重复的字符串数组, arrs_2_index 重复的字符串数组结束索引 
//
int remove_duplicate_arrs(char arrs1[ITEM_LENS][ITEM_ELE_LENS],int arrs_1_index, 
						  char arrs2[ITEM_LENS][ITEM_ELE_LENS],int arrs_2_index, 
						  int *arrs_1_index_p
						 ) 
{
	for (int i = 0;i < arrs_1_index;i++) {
		for (int j = 0;j < arrs_2_index;j++) {
			if (strcmp(arrs1[i], arrs2[j]) == 0) {
				arrs1[i][0] = '\0';
			}
		}
	}
	
	for (int i = 0;i < arrs_2_index;i++) {
		arrs1[arrs_1_index][0] = arrs2[i][0];
		arrs1[arrs_1_index][1] = arrs2[i][1];
		arrs1[arrs_1_index][2] = arrs2[i][2];
		arrs1[arrs_1_index][3] = '\0';
		arrs_1_index++;
	}
	*arrs_1_index_p = arrs_1_index;
	return 0;
}




int connective() {
	char path_arrs[ITEM_LENS][ITEM_ELE_LENS];
	int arrs_1_index = 0;
	int arrs_2_index = 0;
	int *arrs_1_index_p = (int *)malloc(sizeof(int));
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
	printf("\n");
	for (int i = 0;i <arrs_1_index;i++) {
		printf("%s\n", path_arrs[i]);
	}
	printf("---------------------------\n");
	remove_duplicate(path_arrs, arrs_1_index, arrs_1_index_p);
	arrs_1_index = *arrs_1_index_p;
	printf("---------------------------\n");
	for (int i = 0;i <arrs_1_index;i++) {
		if (path_arrs[i][0]!='\0') {
			printf("%s\n", path_arrs[i]);
		}
	}
	return 0;
}

