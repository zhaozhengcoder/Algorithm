#include <iostream>
#include <vector>
using namespace std;


void comb(char * arr,int length,int index,int k,vector<char>& cur ,vector<vector<char>>& res)
{
	//减枝条件1
	if(index>length){
		return ;
	}
	//减枝条件2
	if(cur.size()>k){
		return ;
	}
	if(index==length){
		if(cur.size()==k){
			res.push_back(cur);
		}
		return;
	}
	//进入下一波递归
	//取
	cur.push_back(arr[index]);
	comb(arr,length,index+1,k,cur,res);
	//不取
	cur.pop_back();
	comb(arr,length,index+1,k,cur,res);
}


int main(){
	char * c_arr="abcd";
	vector<char> cur;
	vector<vector<char>> res;
	comb(c_arr,4,0,3,cur,res);

	return 0;
}