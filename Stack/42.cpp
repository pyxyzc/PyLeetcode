#include <vector>

using namespace std;

int trap_two_pointer(vector<int> &h)
{
    int            result      = 0;
    pair<int, int> result_pair = {-1, -1};
    int            n           = h.size();
    int            l = 0, r = n - 1;
    while (l < r)
    {
        int area = (r - l) * min(h[l], h[r]);
        if (result < area)
        {
            result_pair = {l, r};
            result      = area;
        }
        if (h[l] < h[r])
        {
            l += 1;
        }
        else
        {
            r -= 1;
        }
    }
    return result;
}

int main()
{
    vector<int> h{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap_two_pointer(h) << endl;
    return 0;
}