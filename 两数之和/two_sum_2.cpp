/*这种解法的前提是，返回的不是数组原来的下标，而是返回数字。因为我们给数组排序的时候
会丢失原来的下标。所以，如果面试官要求我们返回数组原来的下标，那么，你之前使用map的方法
才是正解
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void print_vec(std::vector<int> v)
{
    cout<<"The vector is：";
    std::vector<int> ::iterator it = v.begin();
    for(;it!=v.end();++it)
    {
        cout<<*it <<" ";
    }
}
vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> ans;
    sort(nums.begin(),nums.end());
    print_vec(nums);
    int len = nums.size();
    int left =0;
    int right = len-1;
    while(left<right)
    {
        int a = nums[left];
        int b = nums[right];
        cout<<a<<" "<<b<<endl;
        if(a+b==target)
        {
            cout<<"ok";
            ans.push_back(a);
            ans.push_back(b);
            --right;
            ++left;
        }
        else if(a+b>target)
        {
            --right;
        }
        else
        {
            ++left;
        }
    }
    return ans;
}


int main()
{
    int a[] = {4,6,10,3,5,4,9};
    std::vector<int> v(a,a+7);
    print_vec(v);
    int target;
    cin>>target;
    std::vector<int> ans = twoSum(v,target);
    print_vec(ans);
    return 0;
}
