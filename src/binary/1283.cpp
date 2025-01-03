#include <bits/stdc++.h>

using namespace std;

// https://leetcode.cn/problems/find-the-smallest-divisor-given-a-threshold/description/

// 求符合条件的最小 -> 二分答案

class Solution {
  public:
    bool check(const vector<int>& nums, int n, int mid, int threshold)
    {
        int cnt = 0;

        for (int num : nums) {
            cnt += (num + mid - 1) / mid;
        }

        return cnt > threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold)
    {
        int n = nums.size();
        int l = 1, r = 1e6 + 7;

        // 1,...,1e6+7
        // N,...,Y
        // 即前面是「否」，后面是「是」
        // 所以要找到最小的「是」
        // 我直接反过来！

        // 能确定有答案
        // 因此直接right+1 / left

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(nums, n, mid, threshold)) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return l;
    }
};