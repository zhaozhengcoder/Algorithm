// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include < assert.h> 

using namespace std;

//前置条件1： des的空间大于src
//前置条件2： des和src的地址空间不重合
char *  my_strcpy(const char * src, char * des) {
	assert(src != NULL && des != NULL);
	while (*src != '\0') {
		*des = *src;
		des++; src++;
	}
	*des = '\0';
	return des;
}

//解决 des和src的地址空间重合的问题
char * my_strcpy2(char * src, char * des) {
	assert(src != NULL && des != NULL);

	//先检测地址是否重合
	if (src<des && src + strlen(src) >des) {
		char * end = src + strlen(src) - 1; //指向最后
		char * temp = end - (des - src);
		while (temp >= src) {
			*end = *temp;
			end--;
			temp--;
		}
		return des;
	}
	else {
		//地址不重合
		while (*src != '\0') {
			*des = *src;
			des++; src++;
		}
		*des = '\0';
		return des;
	}
}


int main()
{
	char src[] = "hello world";
	char * des = new char[20];


	my_strcpy2(src, src + 2);
	cout << src << endl;   // not ok

	system("pause");
	return 0;
};