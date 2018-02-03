# 区间合并

For example, 将有交集的区间合并
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].


## 思路
1. 先给每个区间按照start开始的时间排序
    ```
    static bool comp(const Interval &a, const Interval &b) {
        return (a.start < b.start);
    }
    
    vector<Interval> merge(vector<Interval> &intervals) {
    
    sort(intervals.begin(), intervals.end(), comp);

    //todo

    }

    ```

2. 然后创建一个数据结构，保存合并之后的结果
    ```
    vector<Interval> merge(vector<Interval> &intervals) {
        //res 用来保存结果
        vector<Interval> res;
        
        //排序
        sort(intervals.begin(), intervals.end(), comp);

        res.push_back(intervals[0]);
        
        //如果后面的元素的begin时间在res 最后的一个元素的end时间之内，
        //那么就归并这个两个区间，否则不归并
        for (int i = 1; i < intervals.size(); ++i) {
            if (res.back().end >= intervals[i].start) {
                res.back().end = max(res.back().end, intervals[i].end);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
    ```



参考 ： http://www.cnblogs.com/grandyang/p/4370601.html