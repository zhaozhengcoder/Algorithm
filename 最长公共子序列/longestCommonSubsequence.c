#include <iostream>
#include <vector>
#include <string>
using namespace std;

char * a="abcbdab";
const int len_a=7;

char * b="bdcaba";
const int len_b=6;
int mymax(int a,int b,int c){
	int max_item1=max(a,b);
	int max_item2=max(max_item1,c);
	return max_item2;
}

int dp[len_a][len_b];

//暴力递归
int search(int ida,int idb){
	if(ida>len_a || idb>len_b){
		return 0;
	}
	if(ida==len_a && idb==len_b){
		return 0;
		//
	}
	int ret1=-1000000;
	if(a[ida]==b[idb]){
		ret1=search(ida+1,idb+1)+1;
	}
	return mymax(ret1,search(ida+1,idb),search(ida,idb+1));
}

//加入了缓存
int search2(int ida,int idb){
	if(ida>len_a || idb>len_b){
		return 0;
	}
	if(ida==len_a && idb==len_b){
		return 0;
	}
	//如果命中缓存
	if(dp[ida][idb]!=-1){
		return dp[ida][idb];
	}
	else{
		//如果没有命中缓存
		int ret1=-1000000;
		if(a[ida]==b[idb]){
			ret1=search2(ida+1,idb+1)+1;
		}
		int ret2=search2(ida+1,idb);
		int ret3=search2(ida,idb+1);
		int res=mymax(ret1,ret2,ret3);
		dp[ida][idb]=res;
		return res;
	}
}

//动规
int search3(int ida,int idb){
	//init dp 最下边的一行和最右边的一行
	//初始化最下面一行
	for(int j=len_b-1;j>=0;j--){
		if(b[j]!=a[len_a-1]){
			dp[len_a-1][j]=0;
		}
		else{
			for(int k=0;k<=j;k++){
				dp[len_a-1][k]=1;
			}
			break;
		}
	}
	//初始化最右边一列
	for(int i=len_a-1;i>=0;i--){
		if(a[i]!=b[len_b-1]){
			dp[i][len_b-1]=0;
		}
		else{
			for(int k=0;k<=i;k++){
				dp[k][len_b-1]=1;
			}
			break;
		}
	}

	for(int i=len_a-2;i>=0;i--){
		for(int j=len_b-2;j>=0;j--){
			int ret1=-10000;
			if(a[i]==b[j]){
				ret1=dp[i+1][j+1]+1;
			}
			int ret2=dp[i+1][j];
			int ret3=dp[i][j+1];
			dp[i][j]=mymax(ret1,ret2,ret3);
		}
	}
	return dp[0][0];
}


//写成lintcode格式的代码 
//www.lintcode.com/zh-cn/problem/longest-common-subsequence/
class Solution {
public:
    /*
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
	int mymax(int a,int b,int c){
		int max_item1=max(a,b);
		int max_item2=max(max_item1,c);
		return max_item2;
	}

    int longestCommonSubsequence(string &A, string &B) {
        // write your code here
		int a_size=A.size();
		int b_size=B.size();
		int **dp=new int* [a_size];
		for(int i=0;i<A.size();i++){
			dp[i]=new int[b_size];
		}
		// -1
		for(int i=0;i<A.size();i++){
			for(int j=0;j<B.size();j++){
				dp[i][j]=-1;
			}
		}

		//dp
		for(int j=B.size()-1;j>=0;j--){
			if(B[j]!=A[A.size()-1]){
				dp[A.size()-1][j]=0;
			}
			else{
				for(int k=0;k<=j;k++){
					dp[A.size()-1][k]=1;
				}
				break;
			}
		}
		//初始化最右边一列
		for(int i=A.size()-1;i>=0;i--){
			if(A[i]!=B[B.size()-1]){
				dp[i][B.size()-1]=0;
			}
			else{
				for(int k=0;k<=i;k++){
					dp[k][B.size()-1]=1;
				}
				break;
			}
		}
		
		for(int i=A.size()-2;i>=0;i--){
			for(int j=B.size()-2;j>=0;j--){
				int ret1=-10000;
				if(A[i]==B[j]){
					ret1=dp[i+1][j+1]+1;
				}
				int ret2=dp[i+1][j];
				int ret3=dp[i][j+1];
				dp[i][j]=mymax(ret1,ret2,ret3);
			}
		}
		return dp[0][0];

    }
};



int main(){
	//init dp
	for (int i=0;i<len_a;i++){
		for(int j=0;j<len_b;j++){
			dp[i][j]=-1;
		}
	}
	cout<<search(0,0)<<endl;
	cout<<search2(0,0)<<endl;
	cout<<search3(0,0)<<endl;

	//lintcode 
	string A="abcbdab";
	string B="bdcaba";
	Solution s;
	cout<<s.longestCommonSubsequence(A,B)<<endl;

	return 0;
}