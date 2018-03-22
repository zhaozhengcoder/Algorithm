#include<stack>
#include<iostream>
#include<deque>
#include<vector>
#include<string>
#include <sstream>
#include <assert.h>
using namespace std;

int my_atoi(char * c) {
	assert(*c >= '0' && *c <= '9');
	int diff = (*c) - '0';
	return diff + 0;
}

int string_to_int(string str) {
	int count = 0;
	int base = 10;
	int sum = 0;
	for (int i = str.size() - 1; i >= 0; i--) {
		char temp = str[i];
		int ret = my_atoi(&temp);
		sum += ret * pow(base, count);
		count++;
	}
	return sum;
}

int main() {
	string str = "123";
	cout<<string_to_int(str);
	

	
	system("pause");
	return 0;
}