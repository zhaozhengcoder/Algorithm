class Solution {
public:
// 深度优先查找，用递归。此方法比之前类似广度查找的方法的好处是，可以查找所有可能的情况
int MinAdjustmentCost(vector<int> A, int target)
{
	if (A.size() == 0)
		return 0;

	// 找到最小值和最大值
	int minVal = INT_MAX;
	int maxVal = INT_MIN;
	for (int i = 0; i < A.size(); i++)
	{
		minVal = min(minVal, A[i]);
		maxVal = max(maxVal, A[i]);
	}

	// 初始化辅助数组，每个位置记录从后到前调整的代价
	vector<vector<int> > M(A.size(), vector<int>(maxVal - minVal + 1, INT_MAX));

	vector<int> B(A); // 数组B记录了每次尝试的结果

	// 调用辅助函数
	return MinAdjustmentCostAux(A, B, target, 0, M, minVal, maxVal);
}

// 辅助函数，实现带有表格的递归，从而减少运行次数
// 返回下标为index时，与前一个数字在target限定范围内的最小调整代价
int MinAdjustmentCostAux(vector<int> A, vector<int> B, int target, int index, vector<vector<int> > &M, int minValue, int maxValue)
{
	int n = A.size();
	if (index >= n)
		return 0;

	int dif = 0;
	int minCost = INT_MAX;

	for (int i = minValue; i <= maxValue; i++)
	{
		if (index != 0 && abs(i - B[index-1]) > target)
			continue;

		// 如果查找时发现此位置已经有结果，那么直接返回
		if (M[index][i-minValue] != INT_MAX)
		{
			dif = M[index][i-minValue];
			minCost = min(minCost, dif);
			continue;
		}

		// 此时index位置的值尝试为i
		B[index] = i;
		dif = abs(i - A[index]); // 计算此位置调整的代价
		dif += MinAdjustmentCostAux(A, B, target, index + 1, M, minValue, maxValue); // 加上后面所有数调整的代价，得到的是总代价
		minCost = min(minCost, dif); // 找到每个数字调整的最小代价

		M[index][i-minValue] = dif; // 记录到辅助数组M中，实现减少运行次数

		B[index] = A[index]; // 用于回溯
	}

	return minCost;
}
};

int main(int argc, char const *argv[])
{


	Solution2 s;
	int arr[]={1, 4, 2, 3};
	vector<int> vi(arr,arr+4);
	int targget=1;
	cout<<s.MinAdjustmentCost(vi,target);


	return 0;
}