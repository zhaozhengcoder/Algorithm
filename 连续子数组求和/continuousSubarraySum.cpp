class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of 
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        // Write your code here
		int sum=0;
		int max_sum=0;
		int max_begin=0;
		int max_end=0; 

		int begin=0;
		int end=0;
		int flag=0;

		int neg_flag=0;
		int max_neg=A[0];
		int max_neg_index=0;

		for(int i=0;i<A.size();i++){
			
			if(A[i]>0&&flag==0){
				begin=i;
				flag=1;
			}

			sum=sum+A[i];
			if(sum<0){
				sum=0;
				flag=0;
			}

			if(sum>max_sum){
				end=i;
				max_sum=sum;
				max_begin=begin;
				max_end=end;
				
			}
			//下面的算法解决了有整数 有负数的情况，下面的这种情况是，如果全是负数的话，要怎么办

			if(A[i]>0){
				neg_flag=1;
			}
			else{
				if(A[i]>max_neg){
					max_neg=A[i];
					max_neg_index=i;
				}
			}
		}
		vector<int> res;
		if(neg_flag==0){
			res.push_back(max_neg_index);
			res.push_back(max_neg_index);
			return res;
		}
		else{
			res.push_back(max_begin);
			res.push_back(max_end);
			return res;
		}
    }
};
