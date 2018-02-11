#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void PrintMatrixInCircle(vector<vector<int> > &matrix,int start, vector<int> &ret){
        int rows = (int)matrix.size();
        int columns = (int)matrix[0].size();
        int endX = (columns-1) - start;
        int endY = (rows-1) - start;
        // 从左到右
        for(int i = start; i <= endX; ++i){
            ret.push_back(matrix[start][i]);
        }
        
        // 从上到下，至少2行
        if(endY > start){
            for(int i = start+1;i <= endY;++i){
                ret.push_back(matrix[i][endX]);
            }
        }
        
        // 从右到左，至少2行2列
        if(endX > start && endY > start){
            for(int i = endX-1; i >= start; --i){
                ret.push_back(matrix[endY][i]);
            }
        }
        
        // 从下到上，至少有3行2列
        if(endY > start + 1 && endX > start){
            for(int i = endY-1; i >= start + 1; i--){
                ret.push_back(matrix[i][start]);
            }
        }
    }
    
    
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int rows = (int)matrix.size();
        int columns = (int)matrix[0].size();
        vector<int> ret;
        if(matrix.size() == 0 || columns <=0 || rows <= 0) return ret;
        int start = 0;

        //难点在于理解这个边界条件
        while(columns > start*2 && rows > start*2){
            PrintMatrixInCircle(matrix,start,ret);
            ++start;
        }
        
        return ret;
    }
};


int main(){
	int n1[] = {1, 2, 3, 4} ;
	vector<int> v1(n1,n1+4);
	int n2[] = {5,6,7,8} ;
	vector<int> v2(n2,n2+4);

	int n3[] = {9,10,11,12} ;
	vector<int> v3(n3,n3+4);

	int n4[] = {13,14,15,116} ;
	vector<int> v4(n4,n4+4);

	vector<vector<int> > matrix;
	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);
	matrix.push_back(v4);

	Solution s;
	vector<int> ret=s.printMatrix(matrix);



	return 0;
}