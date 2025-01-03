#include <bits/stdc++.h>

using namespace std;

// 古代密文解读器

// 考古学家K小姐在一处古遗址中发现了一份特殊的密文。
// 这份密文采用了一种独特的编码方式，包含了普通文字和特殊的复制指令。
// 她需要开发一个解码程序来还原原始文本。
// 密文中的普通字母保持原样，而特殊指令格式为(x,y)，
// 表示需要从当前解码结果往回数第x个字符位置开始，复制y个字符到结果末尾。
// 若需要复制的字符数超过可用字符数，则需要循环复制直到满足要求。

// 输入：
// 输入一行字符串，包含大小写英文字母和形如(x,y)的指令串。

// 输出：
// 输出一行字符串，表示解码后的完整文本。

// 样例输入：

// ABCDE(3,2)(2,3)
// ABCDECDCDC

// ABCD(3,8)(10,10)mn
// ABCDBCDBCDBCCDBCDBCDBCmn

// 0<|S|<=1000
// 0<|x|<=99
// 0<|y|<=99
// 解码后的长度不超过2000
// x不会超过当前已解码字符串的长度

int main()
{
    string s;
    cin >> s;

    int         n = s.length();
    stack<char> result;

    int i = 0;
    while (i < n) {
        if (s[i] != '(') {
            result.push(s[i]);

            i += 1;
            continue;
        }

        // (x,y)
        // cout << i << endl;

        i++;
        int x = 0;
        while (s[i] >= '0' && s[i] <= '9') {
            x = x * 10 + s[i] - '0';
            i++;
        }

        i++;
        int y = 0;
        while (s[i] >= '0' && s[i] <= '9') {
            y = y * 10 + s[i] - '0';
            i++;
        }

        // cout << x << " " << y << endl;

        // 先pop出去，一会儿加进来的时候先加一遍完整的
        string tmp;
        for (int j = 0; j < x; j++) {
            tmp += result.top();
            result.pop();
        }

        reverse(tmp.begin(), tmp.end());
        // cout << tmp << endl;

        // 加一遍完整的
        for (char c : tmp) {
            result.push(c);
        }

        int index = 0;
        for (int j = 0; j < y; j++) {
            result.push(tmp[(index++) % tmp.length()]);
            // cout << result.top() << endl;
        }

        i++;
    }

    string ss_result = "";
    while (!result.empty()) {
        ss_result += result.top();
        result.pop();
    }

    reverse(ss_result.begin(), ss_result.end());
    cout << ss_result << endl;

    return 0;
}

// 参考答案：也可以利用好substr，不用stack了

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);

//     string s;
//     cin >> s;
//     string res = "";  // 存储解码结果
//     string tmp = "";  // 临时存储指令参数

//     // 逐字符处理
//     for (char ch : s) {
//         if (isalpha(ch)) {
//             res += ch;
//         }
//         else if (ch == '(') {
//             continue;
//         }
//         else if (ch == ')') {
//             // 解析指令参数
//             int idx = tmp.find(',');
//             int x   = stoi(tmp.substr(0, idx));
//             int y   = stoi(tmp.substr(idx + 1));

//             // 获取需要复制的基础字符串
//             string base = res.substr(res.size() - x);
//             // 计算需要复制的次数和余数
//             int times = y / base.size();
//             int rem   = y % base.size();

//             // 执行复制
//             for (int i = 0; i < times; i++) {
//                 res += base;
//             }
//             res += base.substr(0, rem);
//             tmp = "";
//         }
//         else {
//             tmp += ch;
//         }
//     }

//     cout << res << "\n";
//     return 0;
// }