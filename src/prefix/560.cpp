#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int subarraySum(vector<int>& a, int k)
    {
        int         n = a.size();
        vector<int> s(n + 1);
        s[0] = 0;
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + a[i];
        }

        unordered_map<int, int> mp;
        int                     result = 0;
        for (int j = 0; j <= n; j++) {
            // s[j] - s[i] = k
            auto it = mp.find(s[j] - k);
            if (it != mp.end()) {
                result += it->second;
            }

            mp[s[j]]++;
        }

        return result;
    }
};

int main()
{
    vector<int> a = {1, 1, 1};
    int         k = 2;
    Solution    solution;
    cout << solution.subarraySum(a, k) << endl;
    return 0;
}