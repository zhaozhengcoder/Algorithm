#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <time.h>    
#include <stdio.h>  
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_set>
#include <map>
#include <bitset>

using namespace std;

//这是一个典型的递归的问题，如果按照递归的方式去写，就超时了，因为重复计算了子问题
//所以比较粗暴的方式就是加上缓存dp，保存子问题的计算结果
class Solution {
public:
    /*
     * @param word1: A string
     * @param word2: A string
     * @return: The minimum number of steps.
     */
	int calu_miniDis(map<string,int> &dp,string word1,string word2,int w1_begin,int w2_begin){
		//如果可以命中缓存
		string key1(word1.begin()+w1_begin,word1.end());
		string key2(word2.begin()+w2_begin,word2.end());
		string key=key1+"-"+key2;
		if(dp.find(key)!=dp.end()){
			return dp[key];
		}
		
		//如果word1遍历道路结尾
		if(w1_begin>=word1.size()){
			if(w2_begin>=word2.size()){
				return 0;
			}
			else{
				return word2.size()-w2_begin+1;
			}
		}

		//如果word2遍历到了结尾
		if(w2_begin>=word2.size()){
			if(w1_begin>=word1.size()){
				return 0;
			}
			else{
				//缓存结果
				dp[key]=word1.size()-w1_begin+1;
				return dp[key];
			}
		}

		//如果相等
		if(word1[w1_begin]==word2[w2_begin]){
			return calu_miniDis(dp,word1,word2,w1_begin+1,w2_begin+1);
		}

		int res1=calu_miniDis(dp,word1,word2,w1_begin+1,w2_begin);
		int res2=calu_miniDis(dp,word1,word2,w1_begin,w2_begin+1);
		int res3=calu_miniDis(dp,word1,word2,w1_begin+1,w2_begin+1);

		//缓存结果
		dp[key]=min(min(res1,res2),res3)+1;
		return dp[key];
	}

    int minDistance(string &word1, string &word2) {
        // write your code here
		map<string,int> dp;
		int res=calu_miniDis(dp,word1,word2,0,0);
		return res;
    }
};


int main(int argc, char const *argv[])
{


	Solution s;
	string a="mart";
	string b="karma";
	cout<<s.minDistance(a,b);

	return 0;
}