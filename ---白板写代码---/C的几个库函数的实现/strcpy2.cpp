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

char * my_strcpy2(char * src, char * des) {
	assert(src != NULL && des != NULL);		//排除src==NULL的情况
	assert(des != src + strlen(src));       //排除des的指针恰好指向src的最后一个字符'\0'的地方
	
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
	char src[] = "helloworld";
	char * des = new char[20];


	//assert(1 == 2);
	//cout << src << endl;
	//cout << des << endl;

	//my_strcpy(src, des);

	//cout << src << endl;
	//cout << des << endl;


	//但是对于 src和des地址重合的问题，就会出问题

	//my_strcpy(src + 2, src);
	//cout << src << endl;    //ok

	my_strcpy2(src, src + 2); //原来是 : helloworld
	cout << src << endl;      //输出是 : hehellowor

	system("pause");
	return 0;
};