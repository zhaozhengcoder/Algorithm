class Solution {
public:
    /*
     * @param A: An integer array
     * @return: An integer
     */
    int singleNumberII(vector<int> &A) {
        // write your code here
		map<int,int> mii;
		for(int i=0;i<A.size();i++){
			if(mii.find(A[i])!=mii.end()){
				mii[A[i]]++;
			}
			else{
				mii[A[i]]=1;
			}
		}

		for(auto it =mii.begin();it!=mii.end();it++){
			if(it->second==1){
				return it->first;
			}
		}
    }
    /*
    当a出现一次的时候，ones能保存a。当a出现两次的时候，twos能保存a。 
    当a出现三次的时候，ones和twos都清零。 
    所以，如果一个数值中所有的数都通过这个循环的话，出现三次的数都清零了， 
    有一个数如果出现一次，它保存在ones中；如果出现两次的话保存在twos中。

    class Solution:
    """
    @param A : An integer array
    @return : An integer
    """
    def singleNumberII(self, A):
        # write your code here
        ones = 0
        twos = 0
        for num in A:
            ones = (ones ^ num) & (~twos)  
            twos = (twos ^ num) & (~ones)
        return ones 
    */
};

