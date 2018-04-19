#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


/*
算法的逻辑是

step1 : 先给最小的元素和第二小的元素一起加1，直到加到第二小的元素等于最大的元素。
step2 : 然后下一步给第二小的元素每次加2

*/
int solution(vector<int> & vi) {
	//从小到大排序
	sort(vi.begin(), vi.end());

	//
	int sub1 = vi[2] - vi[0];
	int sub2 = vi[2] - vi[1];

	vi[0] += sub2;   //step1 : 最小的元素和第二小的元素一起加1

	int times2 = (vi[2] - vi[0]) / 2 + (vi[2] - vi[0]) % 2;  // step2 : 然后下一步给第二小的元素每次加2

	return times2 + sub2;
}


int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> vi{ a,b,c };
	
	cout<<solution(vi);

	system("pause");
	return 0;
}