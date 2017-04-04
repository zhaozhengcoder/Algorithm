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


    int backPack(int m, vector<int> A) {
        // write your code here
    	int ** dp=new int *[A.size()];
		for(int i=0;i<A.size();i++){
			dp[i]=new int[m];
		}

    	for(int i=0;i<A.size();i++){
    		dp[i][0]=0;
    	}


    	for(int j=1;j<m+1;j++){
    	
    			if(A[0]<j){
    				dp[0][j]=A[0];
    			}
    			else{
    				dp[0][j]=0;
    			}

    		for(int i=1;i<A.size();i++){
    			if(A[i]>j){
    				dp[i][j]=dp[i-1][j];
    			}
    			else{
    				dp[i][j] = max(dp[i-1][j-A[i]]+A[i],dp[i-1][j]);
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
