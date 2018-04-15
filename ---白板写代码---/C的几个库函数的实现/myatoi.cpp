
#include <iostream>
#include <string>
#include <assert.h>
#include <future>
#include <algorithm>
using namespace std;


int myatoi(char * str) {
	int sign = 1; //表示正数
	long long res = 0;
	int base = 10;

	//如果是空格的话 str++
	while (isspace(*str)) {
		str++;
	}

	if (*str == '-') {
		sign = 0; str++;
	}
	if (*str == '+') {
		sign = 1; str++;
	}

	while (*str >= '0'&&*str <= '9') {
		res = res * base + (*str - '0');
		str++;
	}
	if (sign == 0) {
		res = res * (-1);
	}
	return res;
}

int main()
{
	char c1[] = "12345";
	char c2[] = "+123";
	char c3[] = "-123";
	char c4[] = "   123";
	char c5[] = " 123   ";
	char c6[] = " abcd ";
	char c7[] = " 123ac12312 ";   //注意这种情况只能输出123

	cout << c1 << "  " << myatoi(c1) << endl;
	cout << c2 << "  " << myatoi(c2) << endl;
	cout << c3 << "  " << myatoi(c3) << endl;
	cout << c4 << "  " << myatoi(c4) << endl;
	cout << c5 << "  " << myatoi(c5) << endl;
	cout << c6 << "  " << myatoi(c6) << endl;
	cout << c7 << "  " << myatoi(c7) << endl;



	system("pause");
	return 0;
};
