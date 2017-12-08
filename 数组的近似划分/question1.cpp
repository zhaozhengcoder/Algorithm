#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
	 //new 2
	 //1231 DSAFADSF  dsafd
	int max(int v1,int v2){
		if(v1>v2){
			return v1;
		}
		else{
			return v2;
		}
	}

	//dp[i][j] 表示只考虑前i个物品，在背包重量只有j的情况下，最多可以装入多大的重量
	//那么问题的最优解是dp[A.size-1][m]
    int backPack(int m, vector<int> A) {
        // write your code here
		//init dp
    	int ** dp=new int *[A.size()];
		for(int i=0;i<A.size();i++){
			dp[i]=new int[m];
		}

		//初始化第一列
    	for(int i=0;i<A.size();i++){
    		dp[i][0]=0;
    	}


    	for(int j=1;j<m+1;j++){
			//初始化dp二维数组 每一列的第一个元素
			if(A[0]<j){
				dp[0][j]=A[0];
			}
			else{
				dp[0][j]=0;
			}
			
    		for(int i=1;i<A.size();i++){
				//如果当前物品不能被转入
    			if(A[i]>j){
    				dp[i][j]=dp[i-1][j];
    			}
				//如果可以被装入
    			else{
    				dp[i][j] = max(dp[i-1][j-A[i]]+A[i],dp[i-1][j]);
    			}
    		}
    	}
    	
		for(int i=0;i<A.size();i++){
			for(int j=0;j<m+1;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
		
    	return dp[A.size()-1][m];
    }
};


int main(){
	int arr[]={1,5,7,8,9,6,3,11,20,17};
	vector<int> vi(arr,arr+10);
	
	//m表示背包可以容纳的重量
	int sum=0;
	for(int i=0;i<10;i++){
		sum=sum+arr[i];
	}
	int m=sum/2;

	//下面就是直接调用背包问题的函数了
	Solution s;
	cout<<s.backPack(m,vi);
		
	return 0;
}