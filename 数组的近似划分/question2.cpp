#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//从vi里面去num个的 组合问题（也就是这个目录下 组合问题2）
void comb(vector<int> &vi,int num,int index,vector<int> cur,vector<vector<int>>& res){
	//减枝条件1
	if(index>vi.size()-1 ){
		return ;
	}
	//减枝条件2
	if(cur.size()>num){
		return ;
	}

	if(index==vi.size()-1){
		if(cur.size()==num){
			res.push_back(cur);
		}
	}

	//将当前元素加入
	cur.push_back(vi[index]);
	comb(vi,num,index+1,cur,res);

	//不加入
	cur.pop_back();
	comb(vi,num,index+1,cur,res);
}

int vector_sum(vector<int> vi){
	int sum=0;
	for(auto it=vi.begin();it!=vi.end();it++){
		sum=sum+(*it);
	}
	return sum;
}

int main(){
	//int arr[]={1,2,3,4,5,6,7,8,9,10};
	int arr[]={1,5,7,8,9,6,3,11,20,17};
	const int size=10;
	vector<int> vi(arr,arr+size);

	//m表示背包可以容纳的重量
	int sum=0;
	for(int i=0;i<10;i++){
		sum=sum+arr[i];
	}
	int m=sum/2;


	vector<vector<int>> res;
	vector<int> cur;
	//执行comb函数之后，res里面保存了从数组里面去size/2的所有组合
	comb(vi,size/2,0,cur,res);

	//然后从res里面找到一个最接近sum/2的组合
	int min=abs(vector_sum(res[0])-m);
	for(int i=0;i<res.size();i++){
		int item_sum=abs(vector_sum(res[i])-m);
		if(item_sum<min){
			min=item_sum;
		}
	}

	//输出最接近sum/2的数组的和
	cout<<min<<endl;

	return 0;
}