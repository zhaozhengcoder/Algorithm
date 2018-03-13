#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	bool haspath(vector<vector<char>> matrix,string str){
		//init visited
		vector<vector<bool>> visited;
		for(int i=0;i<matrix.size();i++){
			vector<bool> vb;
			for(int j=0;j<matrix[0].size();j++){
				vb.push_back(false);
			}
			visited.push_back(vb);
		}


		int str_index=0;
		for(int i=0;i<matrix.size();i++){
			for(int j=0;j<matrix[0].size();j++){
				//枚举所有的位置，作为起点
				if(haspath_core(matrix,str,str_index,visited,i,j)==true){
					return true;
				}
			}
		}
		return false;
	}
	
	//core
	bool haspath_core(vector<vector<char>> matrix,string str,int & str_index,vector<vector<bool>> &visited,int cur_i,int cur_j){
		//success
		if(str_index==str.size()){
			return true;
		}
		//合法性检查
		if(cur_i<0 || cur_j<0 ||cur_i>=matrix.size() || cur_j>=matrix[0].size()||visited[cur_i][cur_j]==true){
			return false;
		}

		//找到
		if(matrix[cur_i][cur_j]==str[str_index]){
			str_index++;
			visited[cur_i][cur_j]=true;

			bool haspath_flag=haspath_core(matrix,str,str_index,visited,cur_i+1,cur_j) || haspath_core(matrix,str,str_index,visited,cur_i-1,cur_j)|| haspath_core(matrix,str,str_index,visited,cur_i,cur_j+1)||haspath_core(matrix,str,str_index,visited,cur_i,cur_j-1);
			
			if(haspath_flag==false){
				visited[cur_i][cur_j]=false;
				str_index--;
			}
			return haspath_flag;
		}
		//没找到
		else
		{
			return false;
		}
	}

};

int main(){
	char n1[] = {'a','b','t','g'} ;
	vector<char> v1(n1,n1+4);
	char n2[] = {'c','f','c','s'} ;
	vector<char> v2(n2,n2+4);
	char n3[] = {'j','d','e','h'} ;
	vector<char> v3(n3,n3+4);


	vector<vector<char> > matrix;
	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);


	Solution s;
	cout<<s.haspath(matrix,"bfce");  //true
	//cout<<s.haspath(matrix,"abfb");  -> false



	return 0;
}