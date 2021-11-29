# include "string_utils.h"
# include <stdlib.h>
/*
char c_arrs[ITEM_NUMS][ITEM_ONE_LENS];
int arr_index = 0;
int p = ITEM_INIT_VAL;
int q = ITEM_INIT_VAL;
char *stemp="";
//0-0Ϊ������
while (!str_is_equal(stemp,"0-0")) {
scanf("%d-%d", &p, &q);
char *s1 = int_2_char(p);
char *s2 = int_2_char(q);
char *str = combine_string(s1, s2);
stemp = str;
//c_arrs[arr_index] = str;
printf("%s\n", str);
}
return 0;
*/

char *combine_string(char *s1, char *s2) {
	int len1 = get_str_len(s1);
	int len2 = get_str_len(s2);
	char *s_ret = malloc(sizeof(char)*(len1 + len2 + 2));
	char *s_ret_start = s_ret;
	char c1 = *s1;
	while (c1 != '\0') {
		*(s_ret++) = *(s1++);
		c1 = *(s1);
	}
	*(s_ret++) = '-';
	char c2 = *s2;
	while (c2 != '\0') {
		*(s_ret++) = *(s2++);
		c2 = *(s2);
	}
	*(s_ret) = '\0';
	return s_ret_start;
}


int   get_str_len(char *s1) {
	int len = 0;
	char c1 = *s1;
	while (c1 != '\0') {
		len++;
		c1 = *(++s1);
	}
	return len;
}


char *get_char_mem(int num_len) {
	char *ret = malloc(sizeof(num_len + 1));
	return ret;
}


char *int_2_char(int val) {
	if (val == 0) {
		return "0";
	}
	int num_len = get_int_len(val);
	char *ret = get_char_mem(num_len);
	int shang = val;
	int scale = 10;
	int yu = 0;
	int char_index = 0;
	while (shang != 0) {
		int yu = shang % scale;
		shang = shang / scale;
		char c1 = int_2_char_10(yu);
		ret[char_index++] = c1;
	}
	*(ret + char_index) = '\0';
	ret = reverse_string(ret, num_len);
	return ret;
}

char int_2_char_10(int val) {
	if (val>9 || val <0) 
	{
		printf("error!");
		system("pause");
		exit(EXIT_FAILURE);
		return 0;
	}
	return  (char)(val + 48);
}

char* reverse_string(char *str, int len) {
	char *ret_str = malloc(sizeof(len + 1));
	char *ret_str_index = ret_str;
	int flag = 0;
	for (char *tmp = str + len;tmp >= str;tmp--) {
		if (flag == 1) {
			*(ret_str_index++) = *tmp;
		}
		if ((*tmp == '\0')) {
			flag = 1;
		}
	}
	*(ret_str_index) = '\0';
	return ret_str;
}

/*
***
0 diff between 1-9  0 is exception for N+
*/
int  get_int_len(int val) {
	//�ض�ʽ ����function��ͽ����������жϣ����������ֱ��return,�ض�ʽ�ĺô����򵥣����ˣ�ֱ�ӡ�
	if (val == 0) {
		return 1;
	}
	int len = 0;
	while (val != 0) {
		val = val / 10;
		len++;
	}
	return len;
}

int str_is_equal(char *s1, char *s2) {
	int ret = 0;
	if (get_str_len(s1) != get_str_len(s2)) {
		return ret;
	}
	while ((*s1) != '\0') {
		if ((*s1++) != (*s2++)) {
			return ret;
		}
	}
	ret = 1;
	return ret;

}


void str_arrs_copy(char *s, char *s1) {
	char *temp = s1;
	while (*temp != '\0') {
		*(s++) = *(temp++);
	}
	*s = '\0';
}

//��ά����ֻ��ʡ�Ե���һά
void str_arrs_2_copy(char arr[][11]) {
	//������β�arr �����˻�Ϊָ��,��ӡsizeof(arr) ��ָ����ֽ���4
	//arr[0]Ϊ��ά�����еĳ���Ϊ11������,��ӡsizeof(arr[0])Ϊ11���ֽ���,��Ȼ�βζ�ά����
	//�����˻�Ϊָ��(����c���Ժ����Ķ���涨��,��ʽ���������˻�Ϊָ��,����ָ��[0]�������Ķ�����ӡ��֪���Ǳ�����������Ϣ��)
	int len1 = sizeof(arr);
	int len = sizeof(arr[0]);
	for (int i = 0;i <len;i++) {

	}
	printf("len1= %d\n", len1);
	printf("len= %d\n", len);
}
//������Ϊ�βδ��ݣ������˻���ָ�� sizeof() 4 ��byte
void str_arrs_1_copy(char arr[]) {
	printf("%d\n", sizeof(arr));
}