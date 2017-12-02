#include <iostream>
#include <vector>
using namespace std;

void subset(char * arr,int length,int index,vector<char>& cur,vector<vector<char>>& res){
	//递归结束条件
	if (index>length){
		return ;
	}
	//满足条件
	if(index==length){
		res.push_back(cur);
	}
	//进入下一波递归, 对于一个元素，有两种情况，一是取，二是不去
	//取
	cur.push_back(arr[index]);
	subset(arr,length,index+1,cur,res);
	//不取
	cur.pop_back();
	subset(arr,length,index+1,cur,res);
}


int main(){
	char * c_arr="abc";
	vector<char> cur;
	vector<vector<char>> res;
	subset(c_arr,3,0,cur,res);

	return 0;
}