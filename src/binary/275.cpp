#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/h-index-ii/solutions/2504326/tu-jie-yi-tu-zhang-wo-er-fen-da-an-si-ch-d15k/

// Why 二分答案？

// 单调性，具体到这道题目：
// 如果至少有2篇论文的引用次数>=2，则必然有1篇论文的引用次数>=1
// 如果至少有3篇论文的引用次数>=3，则必然有2篇论文的引用次数>=2
// ...

// 范围：0-n（0必然满足，则1-n）
// check：是否有i篇论文的引用次数>=i

// 二分的区间不一定包含答案

class Solution {
  public:
    bool check(const vector<int>& citations, int n, int mid)
    {
        // 至少有mid篇论文的引用次数>=mid
        // 要求对数时间复杂度，肯定是O(1)
        // 直接从后往前看mid篇，最后一篇是n-1
        // 要一篇，看n-1是否符合？
        // 要两篇，看n-2是否符合？
        // ...
        // 要mid篇，看n-mid是否符合？

        return citations[n - mid] >= mid;
    }
    int hIndex(vector<int>& citations)
    {
        int n = citations.size();
        int l = 1, r = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(citations, n, mid)) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        // 这里注意循环不变量
        // 循环结束后right == left-1
        // right现在是最大的回答为「是」的数
        // left是最小的回答为「否」的数（在循环中则是下一个可能回答为「是」的数）

        return r;
    }
};