class Solution2 {
public:
    /*
     * @param A: An integer array
     * @param target: An integer
     * @return: An integer
     */
	bool isok(vector<int> arr,int target,int &diff,int &index){
		for(int i=0;i<arr.size()-1;i++){
			int j=i+1;
			if(abs(arr[i]-arr[j])>target){
				diff=arr[i]-arr[j];
				index=i;
				return false;
			}
		}
		return true;
	}

	int calu_min(map<vector<int>,int> &dp,vector<int> &A, int target){
		//查询缓存
		if(dp.find(A)!=dp.end()){
			return dp[A];
		}

		
		//减枝条件
		int diff=0;
		int index=0;
		bool ret=isok(A,target,diff,index);
		if(ret==true){
			return 0;
		}
		else{
			if(diff>0){
				A[index]-=1;
				int res1=calu_min(dp,A,target);
				A[index]+=1; //
				


				A[index+1]+=1;
				int res2=calu_min(dp,A,target);
				A[index+1]-=1;
				

				dp[A]=min(res1,res2)+1;
				return dp[A];
			}
			else{
				//diff <0 
	
				A[index]+=1;
				int res1=calu_min(dp,A,target);
				A[index]-=1;


				A[index+1]-=1;
				int res2=calu_min(dp,A,target);
				A[index+1]+=1;


				dp[A]=min(res1,res2)+1;
				return dp[A];
			}
			
		}

	}

    int MinAdjustmentCost(vector<int> &A, int target) {
        // write your code here
		map<vector<int>,int> dp;
		int ret = calu_min(dp,A,target);
		return ret;
    }
};

int main(int argc, char const *argv[])
{


	Solution2 s;
	int arr[]={1, 4, 2, 3};
	vector<int> vi(arr,arr+4);
	int target=1;
	cout<<s.MinAdjustmentCost(vi,target);


	return 0;
}