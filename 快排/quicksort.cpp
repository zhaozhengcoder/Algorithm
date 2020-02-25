#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <queue>
#include <algorithm>
#include <memory>
using namespace std;

int get_partition(vector<int> &vi, int begin, int end)
{
	int partition = vi[end];
	int sorted = begin;
	for (int i = begin; i < end; i++)
	{
		if (partition > vi[i])
		{
			swap(vi[i], vi[sorted]);
			sorted++;
		}
	}
	swap(vi[sorted], vi[end]);
	return sorted;
}

void quicksort(vector<int> & vi,int begin,int end)
{
	if (begin < end)
	{
		int index = get_partition(vi, begin, end);
		quicksort(vi, begin, index - 1);
		quicksort(vi, index + 1, end);
	}
}

void topk(vector<int> & vi,int k)
{
	int begin = 0;
	int end = vi.size() - 1;
	int index = get_partition(vi, begin, end);

        while (index != k-1)
        {
            if (index < k-1)
            {
                begin = index + 1;
                end = end;
                index = get_partition(nums, begin, end);
            }
            else
            {
                begin = begin;
                end = index - 1;
                index = get_partition(nums, begin, end);
            }
        }

	cout << vi[index] << endl;
}

int main()
{

	vector<int> vi = { 4,12,1,10,5,7,0,3,2,55 };

	quicksort(vi, 0, vi.size() - 1);

	for (auto i : vi)
	{
		cout << i << " ";
	}


	topk(vi, 3);
	topk(vi, 4);
	topk(vi, 5);
	return 0;
}
