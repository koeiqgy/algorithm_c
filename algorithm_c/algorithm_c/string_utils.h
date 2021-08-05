/**
10以内正整数数字转为字符 0-9  ascii 48-57
**/
char  int_2_char_10(int val);
/***
将整型数值转为char数组类型
***/
char* int_2_char(int val);
/**
将字符串逆序
**/
char* reverse_string(char *str, int len);
/*
返回整型数据的位数(辗转除10法)
*/
int   get_int_len(int val);

/*
返回字符串的位数
*/
int   get_str_len(char *s1);


/*
用'-'连接字符串
*/
char *combine_string(char *s1, char *s2);

/*
判断两个字符串是否相等  1 相等 0 不相等
*/
int str_is_equal(char *s1, char *s2);

/*
给字符串赋值
*/
void str_arrs_copy(char *s, char *s1);