#include <bits/stdc++.h>

using namespace std;

// A 公园正在统计游客的参观情况。
// 该公园全天 24 小时开放，游客可以在任意时刻进入和离开。
// 现在园方收集了一段时间内所有游客的进园和离园时间，
// 需要计算在这段时间内，公园实际接待游客的总时长（即只要有游客在园内的时间总和）。

// 输入
// m - 游客总人数
// 接下来 m 行：
// 每行两个正整数 start_i 和 end_i
// 分别表示第 i 个游客进入和离开公园的时间
// 0 < m < 10^6
// 0 < start_i < 10^5
// 0 < end_i < 10^5
// 0 < end_i - start_i < 10^3

// 输出
// 整数 k 表示公园接待游客的总时长

// 3
// 10 11
// 1 2
// 1 5

// 5

// 1
// 1 12

// 11

// 排序 + 遍历加可以过 OJ 上全部案例，但是实际中感觉必须用差分过一些刁钻案例

// int main()
// {
//     int m;
//     cin >> m;
//     vector<pair<int, int>> times;

//     for (int i = 0; i < m; i++) {
//         int start, end;
//         cin >> start >> end;
//         times.push_back({start, end});
//     }

//     sort(times.begin(), times.end(),
//          [](const pair<int, int>& a, const pair<int, int>& b) {
//              return a.first < b.first;
//          });

//     int last_start = -1;
//     int last_end   = -1;

//     int result = 0;

//     for (auto& t : times) {
//         int start = t.first;
//         int end   = t.second;

//         if (start == last_start) {
//             last_end = max(last_end, end);
//         }
//         else {
//             // 上个周期就定下来了
//             // 看有无重合
//             // cout << last_end << " " << start << endl;
//             if (last_end < start) {
//                 result += last_end - last_start;

//                 last_start = start;
//                 last_end   = end;
//             }
//             else {
//                 result += start - last_start;

//                 last_start = start;
//                 last_end   = max(last_end, end);
//             }
//         }
//     }

//     result += last_end - last_start;

//     cout << result << endl;
//     return 0;
// }

const int N = 100007;

int main()
{
    int m;
    cin >> m;
    vector<int> d(N + 1, 0);

    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        d[start]++;
        d[end]--;
    }

    for (int i = 1; i <= N; i++) {
        // a[0], a[1], a[2], ... , a[n-1]
        // d[0] = a[0]
        // d[1] = a[1] - a[0]
        // d[2] = a[2] - a[1]
        // ...
        // d[n-1] = a[n-1] - a[n-2]
        d[i] += d[i - 1];
    }

    for (int i = 1; i <= N; i++) {
        d[i] = d[i] != 0 ? 1 : 0;
    }

    cout << count(d.begin(), d.end(), 1) << endl;
    return 0;
}
