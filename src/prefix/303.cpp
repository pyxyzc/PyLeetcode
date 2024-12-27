#include <bits/stdc++.h>

using namespace std;

class NumArray {
  public:
    NumArray(vector<int>& a)
    {
        int n = a.size();
        s.resize(n + 1);
        s[0] = 0;
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + a[i];
        }
    }

    int sumRange(int left, int right)
    {
        return s[right + 1] - s[left];
    }

  private:
    vector<int> s;
};

int main()
{
    vector<int> a   = {1, 2, 3, 4, 5};
    NumArray*   obj = new NumArray(a);
    cout << obj->sumRange(1, 3) << endl;
    cout << obj->sumRange(0, 4) << endl;
    cout << obj->sumRange(2, 4) << endl;
    return 0;
}