#include <iostream>
#include <vector>
using namespace std;


//递归版本的问题就是复杂度太高
class Solution {
public:
	//递归
	int calu_maxpath(vector<vector<int>> matrix,int index_i,int index_j){
		if(index_i==0||index_j==0){
			if(index_i==0 && index_j!=0){
				int sum=0;
				for(int j=0;j<=index_j;j++){
					sum+=matrix[0][j];
				}
				return sum;
			}
			else if(index_i!=0 && index_j==0){
				int sum=0;
				for(int i=0;i<=index_i;i++){
					sum+=matrix[i][0];
				}
				return sum;
			}
			else {
				//index-i==0 && index-j==0
				return matrix[0][0];
			}
		}
		else{
			int res1=calu_maxpath(matrix,index_i-1,index_j);
			int res2=calu_maxpath(matrix,index_i,index_j-1);
			int ret=max(res1,res2)+matrix[index_i][index_j];
			return ret;
		}
	}

	//递归版本
	int findmaxgiftpath_recursion(vector<vector<int>> matrix){
		int ret=calu_maxpath(matrix,matrix[0].size()-1,matrix.size()-1);
		return ret;
	}
};


int main(){
	int n1[] = {1, 10, 3, 8} ;
	vector<int> v1(n1,n1+4);
	int n2[] = {12, 2,9,6} ;
	vector<int> v2(n2,n2+4);

	int n3[] = {5,7,4,11} ;
	vector<int> v3(n3,n3+4);

	int n4[] = {3,7,16,5} ;
	vector<int> v4(n4,n4+4);

	vector<vector<int> > matrix;
	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);
	matrix.push_back(v4);



	Solution s;
	cout<<s.findmaxgiftpath_recursion(matrix);


	return 0;
}