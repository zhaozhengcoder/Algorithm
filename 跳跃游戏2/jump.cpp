class Solution {
public:
    /*
     * @param A: A list of integers
     * @return: An integer
     */
    int jump(vector<int> &A) {
        // write your code here
		vector<int> dp(A.size(),-1);
		if(A.size()==1){
			return 0;
		}
		dp[A.size()-1]=0;
		for(int i=A.size()-2;i>=0;i--){
			//如果当前的结点可以直接到达最后面的结点，那么dp[i]=1
			if(A[i]+i>=A.size()-1){
				dp[i]=1;
				continue;
			}
			//如果不能直接跳过去，那么就调到一个跳的步骤最少的一点
			int min_jump=INT_MAX;
			for(int j=1;j<=A[i];j++){
				if(dp[i+j]!=-1){
					if(min_jump>dp[i+j]+1){
						min_jump=dp[i+j]+1;
					}
				}
			}
			dp[i]=min_jump;
		}
		return dp[0];
    }
};

