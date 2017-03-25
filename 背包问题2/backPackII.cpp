class Solution {
public:
	/**
	* @param m: An integer m denotes the size of a backpack
	* @param A & V: Given n items with size A[i] and value V[i]
	* @return: The maximum value
	*/
	int backPackII(int m, vector<int> A, vector<int> V) {
		// write your code here
		
		//创建一个二维数组 dp[n][m]
		int n = A.size();
		int ** dp = new int *[n];
		for (int i = 0; i < n; i++) {
			dp[i] = new int[m+1];
		}


		//print
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j <= m; j++) {
		//		dp[i][j] = 0;
		//		cout << dp[i][j]<<"  ";
		//	}
		//	cout << endl;
		//}

		//初始化第一列
		for (int i = 0; i < n; i++) {
			dp[i][0] = 0;
		}


		//初始化第一行
		for (int i = 1; i <=m; i++) {
			if (i >= A[0]) {
				dp[0][i] = V[0];
			}
			else {
				dp[0][i] = 0;
			}
		}




		for (int j = 1; j <= m; j++) {
			for (int i = 1; i < n; i++) {

				int v1 = dp[i - 1][j];
				int v2 = 0;
				if (j >= A[i]) {
					v2 = dp[i - 1][j - A[i]]+V[i];
				}

				if (v1 > v2) {
					dp[i][j] = v1;
				}
				else {
					dp[i][j] = v2;
				}
			}
		}

		//print
		//cout << "print" << endl;
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j <= m; j++) {
		//		cout << dp[i][j] << "  ";
		//	}
		//	cout << endl;
		//}


	//	cout << endl;
	//	cout<< dp[n - 1][m];
		return dp[n-1][m];
	}
};
