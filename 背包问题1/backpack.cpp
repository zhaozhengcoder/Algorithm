//这个在onenote里面的oj笔记面里面，有以前看算法导论的时候，画的一个图，结合一下看，可能会更快一点

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
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
				//如果当前物品超过背包能装的最大重量
    			if(A[i]>j){
    				dp[i][j]=dp[i-1][j];
    			}
				//如果没有超过
    			else{
					//dp[i-1][j] 表示不装
					//dp[i-1][j-A[i]] +A[i] 表示装，装的话，就是在dp[i-1][j-A[i]]的基础上面，然后把当前物品装入
    				dp[i][j] = max(dp[i-1][j-A[i]]+A[i] , dp[i-1][j]);
    			}
    		}
    	}
    	/*
		for(int i=0;i<A.size();i++){
			for(int j=0;j<m+1;j++){
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
		*/
    	return dp[A.size()-1][m];
    }
};
