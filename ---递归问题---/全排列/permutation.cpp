#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <time.h>    
#include <stdio.h>  
#include <string>

using namespace std;

//一个典型的递归问题
void per(string & str,int index,vector<string> &res){
	//递归的结束条件
	if(index==str.size()){
		res.push_back(str);
		return ;
	}

	for(int i=index;i<str.size();i++){
		//进入下一层递归
		swap(str[index],str[i]);
		per(str,index+1,res);
		//从递归里面出来的时候，清除状态
		swap(str[index],str[i]);
	}
}

int main(){
    string str="abc";
	vector<string> res;
	per(str,0,res);


    return 0;
}