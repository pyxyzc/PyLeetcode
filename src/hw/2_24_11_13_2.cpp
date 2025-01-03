#include <bits/stdc++.h>

using namespace std;

// 字符串集合的最大交集查询

// K小姐在整理文件夹时发现每个文件夹中都有一些文件名，
// 她想知道不同文件夹之间共同包含的文件数量。
// 具体来说，对于每个文件夹，
// 她想找到与它共同文件数量最多的其他文件夹（如果有多个相同的取编号最小的），
// 以及这个最大的共同文件数量。

// 输入
// n - 文件夹数量
// 接下来 n 个部分：
// 第一行整数 A_i 表示第 i 个文件夹中的文件数量
// 随后 A_i 行，每行一个字符串，表示文件名

// 输出：
// n 行
// 每行两个整数
// 第一个数字 j 表示与第 i 个文件夹共同文件数最多的文件夹编号
// 第二个数组 x 表示这两个文件夹的共同文件数量

// Example:

// 4
// 3
// 123
// 456
// 789
// 3
// 234
// 345
// 4567
// 5
// 123
// 456
// 789
// 0123
// 4567
// 1
// 6789

// 3 3
// 3 1
// 1 3
// 1 0

// 数据范围
// 1 < n <= 100
// 0 < A_i <= 100
// 0 < len(s) <= 100
// 字符串只包含大小写字母与数字

// 模拟题：对于集合操作进行模拟
// 由于数据量不大，直接遍历求交集
// O(N^2) 的外层遍历
// 内层比较，即求交集，哈希 O(1) 查一个元素是否存在
// 100 * 100 * 100
// 完全可以接受

int main()
{
    int n;
    cin >> n;

    vector<int>                   a(n, 0);
    vector<unordered_set<string>> files(n, unordered_set<string>{});

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        for (int j = 0; j < a[i]; j++) {
            string t;
            cin >> t;
            files[i].insert(t);
        }
    }

    for (int i = 0; i < n; i++) {
        int maxi       = -1;
        int maxi_index = -1;

        for (int j = 0; j < n; j++) {
            if (j == i)
                continue;

            int count = 0;
            for (auto& file : files[i]) {
                if (files[j].find(file) != files[j].end()) {
                    count++;
                }
            }

            if (count > maxi) {
                maxi       = count;
                maxi_index = j;
            }
        }

        cout << maxi_index + 1 << " " << maxi << endl;
    }

    return 0;
}