#include <bits/stdc++.h>
using namespace std;

// 排序
// 相邻区间交集 -> 不可以完成所有会议
// Why? A,B,C 三个会议 ... 易证
bool canAttendMeetings_sort(vector<vector<int>> &intervals)
{
    if (intervals.empty())
    {
        return true;
    }

    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

    for (int i = 0; i < intervals.size() - 1; i++)
    { 
        if (intervals[i][1] > intervals[i + 1][0])
        {
            return false;
        }
    }
    return true;
}

// 差分法
// 


int main() {
    vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    cout << canAttendMeetings(intervals) << endl;
    return 0;
}