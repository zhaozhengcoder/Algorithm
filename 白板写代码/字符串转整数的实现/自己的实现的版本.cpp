#include <iostream>
#include <vector>

using namespace std;

int myatoi(char * c) {
	//先过滤空格
	while (*c == ' ') {
		c++;
	}

	int sign = 1;
	if (*c == '+' || *c == '-') {
		if (*c == '-') {
			sign = -1;
		}
		c++;
	}

	int val = 0;
	while (*c != '\0' && (*c >= '0' && *c <= '9')) {
		int offset = *c - '0';
		val = val * 10 + offset;
		c++;
	}
	return  val * sign;

}


int main()
{
	
	char s1[] = "123456";
	char s2[] = "+123";
	char s3[] = "-123";
	char s4[] = "   +123    ";

	cout << myatoi(s1) << endl;
	cout << myatoi(s2) << endl;
	cout << myatoi(s3) << endl;
	cout << myatoi(s4) << endl;

	system("pause");
	return 0;
}