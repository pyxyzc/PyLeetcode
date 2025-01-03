#include <bits/stdc++.h>

using namespace std;

// 某团队近期需要组织一支队伍参加拔河比赛，团队共有队员n人，
// 比赛队员人数要求为m人，n>m，n个队员按编号1到n的顺序参加k轮力量测试，每轮的测试成绩用正整数表示。

// 根据n个队员的力量测试成绩选择比赛队员m人，
// 先选择k轮测试中最好成绩最大的队员，若有多人的最好成绩相等，则优先选择其中第二好成绩最大的队员，
// 依次类推，最后若还有相等的情况，则优先选择编号较小的队员。每个人只能被选择一次。

// 输入：
// 第1行，团队队员总数n，比赛要求人数m，测试轮数k
// 第i+1行（i从1到n），第i个队员参与力量测试1-k轮的成绩

// 0<m<n<=10^3
// 0<k<=10^3
// 0<队员力量测试成绩<=10^5

// 按上述选择顺序选出的比赛队员编号的列表，用空格分隔.

// Example：

// 4 3 3
// 10 12 14
// 11 12 13
// 12 15 10
// 12 11 13

// 3 1 2

// Idea：

// 由于存在相同的最大/第二大/第三大可能性，不能只关注最大的几个元素
// 换句话说，本体关键在于对队员维护多个维度的信息（多轮）
// 由于队员数量不大，可以直接暴力模拟，对每个成员的成绩全部降序排列
// 10^3 * 10^3
// n * klogk

struct Player
{
    int         id;
    vector<int> scores;
};

bool cmp(const Player& a, const Player& b)
{
    for (int i = 0; i < a.scores.size(); i++) {
        if (a.scores[i] != b.scores[i]) {
            return a.scores[i] > b.scores[i];
        }
    }

    return a.id < b.id;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<Player> players(n);
    for (int i = 0; i < n; i++) {
        players[i].id = i + 1;
        players[i].scores.resize(k);
        for (int j = 0; j < k; j++) {
            cin >> players[i].scores[j];
        }
        sort(players[i].scores.begin(), players[i].scores.end(),
             greater<int>());
    }

    sort(players.begin(), players.end(), cmp);
    for (int i = 0; i < m; ++i) {
        if (i > 0)
            cout << ' ';
        cout << players[i].id;
    }
    return 0;
}
