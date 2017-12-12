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
