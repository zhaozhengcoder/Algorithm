#include<stack>
#include<iostream>
#include<deque>
#include<vector>
#include<string>
#include <sstream>
using namespace std;


int main() {
	{
		//string to int 
		string str = "123";  //注意：stringstream 是支持负号的
		stringstream ss;
		int num;
		ss << str;
		ss >> num;
		cout << num << endl;

		ss.clear();
	}
	{
		//int to string 
		int n = 100;
		string str;
		stringstream ss;
		ss << n;
		ss >> str;
		cout << str << endl;
		ss.clear();
	}
	
	system("pause");
	return 0;
}