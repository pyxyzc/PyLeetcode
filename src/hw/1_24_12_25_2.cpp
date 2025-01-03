#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// 公司班车上车点规划-让最远的员工少走点路

// 某公司基地搬迁到新地点之后，新规划了一条班车路线，在这条路线上会经过n个小区
// 计划在这些小区中挑选出M个作为上车点，小区的位置可以用一维坐标上的点来表示，小区到上车点的距离为两个坐标点差值的绝对值。
// 现在给给定n个小区的位置，即一维坐标上的整数点，x_1, x_2, ...,
// x_n，要求找出m个上车点，所有小区到最近上车点的距离总和尽可能小，请计算这个最大值能够是多少？
// 当该小区被作为上车点，该小区到上车点的距离为0。

// 输入：

// 第一行有两个整数
// n,m (1<=n,m<=10^5)

// 第二行有n个整数（无重复递增）
// 1<=x_i<=10^6

// 输出：一个整数，表示所有小区到上车点距离的最大值的最小值

// 5 2
// 1 2 3 6 7

// 1

// Idea：

// 二分答案，二分这个最小值（所有小区到上车点距离的最大值的最小值）
// check：
// 贪心考虑，放车站的时候尽可能覆盖到右边的区域，最多能覆盖
// position[i]+mid这个位置，即下一个位置可以跳到
// upper_bound(positions.begin(),
//             positions.end(),
//             positions[i] + mid)
// - positions.begin();

// 最后检查车站数量是否不超过m

bool check(const vector<int>& positions, int n, int m, int mid)
{
    // 先放一个距离其实即position[0]最远的mid的车站

    int cnt = 0;
    int i   = 0;

    while (i < n) {
        int station_pos = positions[i] + mid;
        // 找到最右边的一个小区，使得它不超过 positions[i] + mid
        int j = upper_bound(positions.begin(), positions.end(), station_pos) -
                positions.begin();
        j--;  // 上车点放置在 positions[j]

        cnt++;

        // 从这个上车点向右看，所有小区 <= positions[j] + mid 都被覆盖
        int cover_limit = positions[j] + mid;
        i = upper_bound(positions.begin(), positions.end(), cover_limit) -
            positions.begin();
    }

    return cnt <= m;
}

int main()
{
    int n, m;

    cin >> n >> m;

    vector<int> positions(n);
    for (auto& pos : positions) {
        cin >> pos;
    }

    int left  = 0;
    int right = positions[n - 1] - positions[0];

    int result = right;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (check(positions, n, m, mid)) {
            result = mid;
            right  = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}