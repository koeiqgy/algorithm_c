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
	����һ����ʽΪx-x�ı�ʾ·�����ַ���
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

//��ά�����е�·��ȥ��
int remove_duplicate(char arrs[ITEM_LENS][ITEM_ELE_LENS],int arrs_1_index, int *arrs_1_index_p) {
	//�ظ���·������
	char pds[ITEM_LENS][ITEM_ELE_LENS];
	//�ظ�·����������
	int index = 0;
	//����ά������ͬ������ ����һ��
	for (int i = 0;i < arrs_1_index;i++) {
		for (int j = 0;j < arrs_1_index;j++) {
			//�����i�б������飬���ұ�����һά��Ų���i������д���
			if (strcmp(arrs[i], arrs[j]) == 0 && i!=j) {
				int k = 0;
				//�����洢���ظ������ֶ�����
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


//�ȶ�2�����飬ȥ���ظ��Ķ�ά�����ַ��� 
//arrs1 �ַ�������,       arrs_1_index �ַ��������������, 
//arrs2 �ظ����ַ�������, arrs_2_index �ظ����ַ�������������� 
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
	int flag = 1;//����ѭ���������λ
	while (flag) {
		//scanf ����ֵ����ƥ������ݸ���
		int ret = scanf("%d-%d", &p, &q);
		if (ret == 2) {
			//0-0���������־
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

