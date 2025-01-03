#include <bits/stdc++.h>
#include <ios>

using namespace std;

// https://leetcode.cn/problems/split-array-largest-sum/

class Solution {
  public:
    bool check(const vector<int>& nums, int n, int mid, int k)
    {
        int cnt = 1;
        // 现在要求最大值最大是mid
        // 直接贪心

        int sum = 0;
        int i   = 0;
        while (i < n) {
            int num = nums[i];
            if (sum + num <= mid) {
                sum += num;
                i++;
            }
            else {
                sum = 0;
                cnt++;

                if (cnt > k) {
                    // return false;
                    return true;
                }
            }
        }

        return false;
    }
    int splitArray(vector<int>& nums, int k)
    {
        int n = nums.size();

        int left  = 0;
        int right = 0;
        for (int num : nums) {
            right += num;
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // 0-n
            // 否 / 否 / ... / 是 / 是
            if (check(nums, n, mid, k)) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return left;
    }
};