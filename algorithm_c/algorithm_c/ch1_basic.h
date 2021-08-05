#pragma once
/*
ch:
question:
给定整数对的一个序列，整数对 p-q代表p与q连通，假设连通性具有传递性，p-q连通，q-r连通，则p-r连通。
现设计一个过滤连通无关的程序(也就是筛选出无连通相关性的整数对)，程序可以存储任意多个整数对，输入为整数对p-q，对输入的整数对p-q进行判断，
如果根据现有已存储的整数对，可以得出输入的整数对连通，则跳过，不做任何输出，如果根据现有已存储的整数对，无法得出输入的整数对连通，
则输出该整数对。
thinking:
整数对可以代表任何类型的对象,c语言允许的数据类型为 基础型(整形 浮点型 指针)   聚合性(数组 结构)
*/
// graphics connective
int   connective();

/*
判断是否连通 path_arrs:数据池数组,str:目标连接串, m:二维数组一维度, n:二维数组二维度, arrs_1_index第一维度数据的长度 
*/
int is_connect(char *path_arrs, int m, int n, char *str, int arrs_1_index);