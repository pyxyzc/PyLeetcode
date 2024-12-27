#include <bits/stdc++.h>
#include <sys/select.h>

using namespace std;

// LYA 在一个古老的遗迹中发现了一个 n × n 的宝藏矩阵。每个格子中都有特殊的含义：
// 数值为 0 表示这个位置是空的
// 数值为 −1 表示这个位置有陷阱，无法通过
// 其他正数表示这个位置有价值为该数值的宝藏

// LYA 必须从左上角 (0,0) 出发，最终要回到起点。
// 去程只能向下或向右移动到右下角 (n-1,n-1)，
// 回程只能向上或向左移动。
// 每个位置的宝藏只能收集一次，经过已收集过的位置时不能再次收集。

// 输入：
// n - 矩阵大小
// 接下来 n 行，每行 n 个整数，表示宝藏矩阵

// 输出：
// 能收集到的最大宝藏价值

// Example:

// 3
// 0 2 0
// 1 -1 0
// 3 0 1

// 7

// 4
// 2 0 1 -1
// 0 -1 3 1
// 2 0 1 0
// 4 -1 1 3

// 14

// 数据范围：
// 1 <= n <= 100

// state
// dp[k][i][j] - 走了 k 步后，第一条路路径到达 (i,x1)，第二条路径到达 (j,x_2)
// 时能获得的最大价值 x_1 = k - i x_2 = k - j Note：很简单，要不向右，要不向下

// transition
// i-1,j-1 -> i,j
// i-1,j -> i,j
// i,j-1 -> i,j
// i,j -> i,j

const int N = 107;

int a[N][N];
int dp[2 * N][N][N];

bool inArea(int i, int j, int k, int n)
{
    return i >= 0 && i < n && j >= 0 && j < n && k - i >= 0 && k - i < n &&
           k - j >= 0 && k - j < n;
}

const vector<pair<int, int>> dirs = {{-1, -1}, {-1, 0}, {0, -1}, {0, 0}};

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int k = 0; k < 2 * n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[k][i][j] = INT_MIN / 2;
            }
        }
    }

    dp[0][0][0] = a[0][0];

    for (int k = 1; k < 2 * n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 检查这个点能不能来
                // 两种情况
                // inArea？
                // 是否是陷阱
                if (!inArea(i, j, k, n)) {
                    continue;
                }

                if (a[i][k - i] == -1 || a[j][k - j] == -1) {
                    continue;
                }

                // 找到来自于四种可能性中最好的一个
                int maxi = INT_MIN / 2;
                // 0 <= i < n
                // 0 <= k-i < n
                for (auto& dir : dirs) {
                    int li = i + dir.first;
                    int lj = j + dir.second;

                    if (inArea(li, lj, k - 1, n)) {
                        maxi = max(maxi, dp[k - 1][li][lj]);
                    }
                }

                if (maxi == INT_MIN / 2) {
                    continue;
                }

                // 考虑自己 (i,k-i) / (j,k-j)
                // 是否是同一个格子
                int value =
                    (i == j) ? a[i][k - i] : (a[i][k - i] + a[j][k - j]);
                dp[k][i][j] = maxi + value;
            }
        }
    }

    int result = dp[2 * n - 2][n - 1][n - 1] == INT_MIN / 2 ?
                     0 :
                     dp[2 * n - 2][n - 1][n - 1];

    cout << result << endl;

    return 0;
}