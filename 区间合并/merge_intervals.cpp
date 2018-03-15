#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

struct intervals{
	int begin;
	int end;
};

//从小到大排序
bool comp(const intervals &inter1,const intervals& inter2){
	if(inter1.begin<inter2.begin){
		return true;
	}
	return false;
}

vector<intervals> merge(vector<intervals> & vi)
{
	sort(vi.begin(),vi.end(),comp);

	vector<intervals> res;
	res.push_back(vi[0]);

	for(int i=1;i<vi.size();i++){
		if(res.back().end > vi[i].begin){
			//���Ժϲ�����
			res.back().end=max(res.back().end,vi[i].end);
		}
		else{
			res.push_back(vi[i]);
		}
	}
	return res;
}

int main(){
	intervals inter1;
	inter1.begin=1;
	inter1.end=3;

	intervals inter2;
	inter2.begin=2;
	inter2.end=6;

	intervals inter3;
	inter3.begin=15;
	inter3.end=18;

	intervals inter4;
	inter4.begin=8;
	inter4.end=10;

	vector<intervals> vi;
	vi.push_back(inter1);
	vi.push_back(inter2);
	vi.push_back(inter3);
	vi.push_back(inter4);

	vector<intervals> res=merge(vi);

	return 0;
}