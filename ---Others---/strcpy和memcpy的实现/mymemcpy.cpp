#include<stack>
#include<iostream>
#include<deque>
#include<vector>
#include<string>
using namespace std;

void * my_memcpy(void * src, void * des,size_t size) {
	char * p_src = (char * )src;
	char * p_des = (char * )des;
	while (size > 0) {
		*p_des = *p_src;
		p_des++;
		p_src++;
		size--;
	}
	return p_des;
}

void * my_memcpy2(void * src, void * des, size_t size) {
	char * p_src = (char *)src;
	char * p_des = (char *)des;

	//地址重叠
	if (p_src<p_des && p_src + size >p_des) {
		char * beg_src = p_src + size;  //从后向前复制
		char * beg_des = p_des + size;
		while (size > 0) {
			*beg_des = *beg_src;
			beg_des--; beg_src--;
			size--;
		}
		return des;
	}
	else {
		//正常情况，不重叠
		while (size > 0) {
			*p_des = *p_src;
			p_des++;
			p_src++;
			size--;
		}
		return p_des;
	}
}

int main() {
	int size = 10;
	int * src = new int[10];
	for (int i = 0; i < size; i++) {
		src[i] = i; 
	}
	//输出src
	for (int i = 0; i < size; i++) {
		cout << src[i] << " ";
	}
	cout << endl;

	int * des = new int[10];

	//my_memcpy(src, des,40);
	//地址重叠的情况
	//my_memcpy2(&src[0], &src[2], 20);

	for (int i = 0; i < size; i++) {
		cout << src[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << src[i] << " ";
	}
	cout << endl;


	system("pause");
	return 0;
}