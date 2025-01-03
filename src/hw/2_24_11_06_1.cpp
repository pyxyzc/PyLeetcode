#include <bits/stdc++.h>
#include <climits>

using namespace std;

// 图书馆整理计划

// 在一个图书馆里，一排书架上有L本书，每本书的封面要么是黑色，要么是白色。
// 图书管理员K小姐想要整理这些书籍，
// 使得任何一本黑色封面的书的左边都不能有白色封面的书。
// 为了达到这个目的，她可以将任意一本书重新包装，改变其封面颜色（可以将黑色改为白色，或将白色改为黑色）。
// 请帮助K小姐计算最少需要改变多少本书的封面颜色。

// 输入
// 输入一行，包含一个字符串S，仅由字符B（表示黑色封面）和W（表示白色封面）组成。

// 输出
// 输出一个整数，表示需要改变封面颜色的最少书本数量。

// Example:

// BWBWB
// 2

// BBBWWW
// 0

// 0<L<10000

// Idea：

// 题意 -> 所有黑色书籍必须全部连续排在左边
// 操作数就是将现在情况转变为这个理想情况的操作数

// 对于任意位置i，将前i个书籍全部变为黑色，后面的全部变为白色
// 取最小值即可
// 直接用两个变量遍历维护即可

int main()
{
    string s;
    cin >> s;

    int result = INT_MAX;
    int n      = s.length();

    int prev = 0;  // 左边黑色，左边包括自己一共i个
    int last = 0;  // 右边白色，右边一共n-i个

    // 从index=0开始
    prev += s[0] == 'B';
    for (int i = 1; i < n; i++) {
        if (s[i] == 'W') {
            last++;
        }
    }

    for (int i = 0; i < n; i++) {
        int left  = (i + 1) - prev;
        int right = (n - i - 1) - last;
        // cout << i << ": " << left << " " << right << endl;
        result = min(result, left + right);

        // update
        if (i == n - 1) {
            break;
        }

        prev += s[i + 1] == 'B';
        last -= s[i + 1] == 'W';
    }

    cout << result << endl;

    return 0;
}