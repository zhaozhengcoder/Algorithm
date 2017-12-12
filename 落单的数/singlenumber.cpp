class Solution {
public:
	/**
	* @param A: Array of integers.
	* return: The single number.
	*/
	int singleNumber(vector<int> &A) {
		// write your code here
		if(A.size()==0){
		    return 0;
		}
		if (A.size() == 1) {
			return A[0];
		}

		set<int> si;
		si.insert(A[0]);
		for (int i = 1; i < A.size(); i++) {
			if (si.find(A[i]) == si.end()) {
				//bu chunzai 
				si.insert(A[i]);
			}
			else {
				si.erase(A[i]);
			}
		}

		auto it = si.begin();
		return *it;
	}
};
/*
利用异或^运算，两个相同的数的异或的结果是0，就这样遍历之后的结果就是那个数
class Solution:
    """
    @param A : an integer array
    @return : a integer
    """
    def singleNumber(self, A):
        # write your code here
        if A.length ==0:
            return 0 
        n = A[0]
        for i in range(1,len(A)):
            n = n ^ A[i]
        return n 
*/