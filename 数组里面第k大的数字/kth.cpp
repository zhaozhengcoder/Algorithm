class Solution{
public:
	//使用快排划分的思想
    //partition 和partiton2 的区别是partition是一个通用的，partition2指定了搜索的区间
	//int partition(vector<int>& nums){
	//	int i=0;
	//	int j=nums.size()-1;
	//	int part=nums[0];

	//	while(i<j){
	//		while(nums[j]>=part&&(i<j)){
	//			j--;
	//		}
	//		if(!(i<=j)){
	//			break;
	//		}
	//		if(nums[j]<part){
	//			swap(nums[i],nums[j]);
	//			i++;
	//		}

	//		while(nums[i]<=part&&(i<j)){
	//			i++;
	//		}
	//		if(!(i<=j)){
	//			break;
	//		}
	//		if(nums[i]>part){
	//			swap(nums[i],nums[j]);
	//			j--;
	//		}
	//	}

	//	//如果是快排的话，进入下一层的递归
	//	//但是，我们这里不是快排
	//	return i;
	//}

	int partition2(vector<int>& nums,int begin,int end){
		int i=begin;
		int j=end;
		int part=nums[begin];

		while(i<j){
			while(nums[j]>=part&&(i<j)){
				j--;
			}
			if(!(i<=j)){
				break;
			}
			if(nums[j]<part){
				swap(nums[i],nums[j]);
				i++;
			}

			while(nums[i]<=part&&(i<j)){
				i++;
			}
			if(!(i<=j)){
				break;
			}
			if(nums[i]>part){
				swap(nums[i],nums[j]);
				j--;
			}
		}

		//如果是快排的话，进入下一层的递归
		//但是，我们这里不是快排
		return i;
	}
	void kth(int k, vector<int> nums,int begin,int end,int& res){
		//返回的第k大元素的下标，比如第4大的元素的index=3
		int index=partition2(nums,begin,end);
		//index_th表示返回的元素是第几大的
		int index_th=index+1;

		if(index_th==k){
			int ret=nums[index];
			res=ret;
		}
		//要找第七大的元素，结果现在找到了第五大的（index=5），那么就在后面找第（7-5）大的元素
		else if (index_th<k){
			kth(k,nums,index+1,end,res);
		}
		else{
			kth(k,nums,begin,index-1,res);
		}
	}

	 int kthLargestElement(int k, vector<int> nums) {
		 int res=-1;
		 //比如说第十大的元素，转换成k_index= nums.size()-k+1，k_index=1，相当于转换成第1小的元素
		 int k_index=nums.size()-k+1;
		 kth(k_index,nums,0,nums.size()-1,res);
		 return res;
	 }
};

int main(){ 
    int arr[]={1,2,3,4,5,6,8,9,10,7};
	const int len=10;
	int k_th=10;
	//int arr[]={9,3,2,4,8};
	//const int len=5;
	//int k_th=3;
	vector<int> vi(arr,arr+len);
	Solution s;
	int ret=s.kthLargestElement(k_th,vi);
	cout<<ret<<endl;
	
    system("pause");
	return 0;
}