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

using namespace std;

 struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
  };

class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
	/*
	思路：
	对于一个点i，计算这个点i到其他的点（i+1，end）的所有的点的k，如果这个k相同，表示有多一个点在同一条直线上面k_map[k]++，
	max_item记录了当前结点到[i+1,end]的店里面有多少点在同一条线上面
	遍历所有的i，会求出一个最大的max_iem,这个就是结果
	*/
    int maxPoints(vector<Point>& points) {
        // Write your code here
		if(points.size()==0){
			return 0;
		}
		map<double,int> k_map;
		//记录结果
		int max_result=1;
		

		for(int i=0;i<points.size();i++){
			//判断对于结点i，最多有几个点和他们是一条线的
			double k=0;
			int max_item_num=1;
			int same_point=0;

			for(int j=i+1;j<points.size();j++){

				//如果这两个点是相同的
				if(points[i].x==points[j].x && points[i].y==points[j].y){
					same_point++;
					continue;
				}
				else if(points[i].x==points[j].x){
					k=INT_MAX;
				}
				else{
					k=float((points[j].y-points[i].y))/float((points[j].x-points[i].x));
				}

				int cur_item_num=1;
				if(k_map.find(k)!=k_map.end()){
					//这个斜率已经存在了，value++
					k_map[k]++;
					cur_item_num=k_map[k];
				}else{
					//如果当前的k是不存在的，表示这个有两个点在这一条线上
					k_map[k]=2;
					cur_item_num=2;
				}
				//更新经过直线的最多的点
				max_item_num=max(max_item_num,cur_item_num);
			}//for j
			k_map.clear();
			max_result=max(max_item_num+same_point,max_result);
		}//for i
		return max_result;
    }
};


int main(int argc, char const *argv[])
{
	vector<Point> points;
	points.push_back(Point(0,0));
	points.push_back(Point(0,0));
	//points.push_back(Point(0,0));
	//points.push_back(Point(1,3));

	Solution s;
	cout<<s.maxPoints(points);
	

	return 0;
}