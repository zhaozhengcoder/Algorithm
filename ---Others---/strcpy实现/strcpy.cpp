//#include "stdafx.h"
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



int main()
{
	char src[] = "hello world";
	char * des = new char[20];

	cout << src << endl;
	cout << des << endl;

	my_strcpy(src, des);

	cout << src << endl;
	cout << des << endl;


	//但是对于 src和des地址重合的问题，就会出问题

	my_strcpy(src + 2, src);
	cout << src << endl;    //ok

	//my_strcpy(src, src + 2);
	//cout << src << endl;   // not ok

	system("pause");
	return 0;
};