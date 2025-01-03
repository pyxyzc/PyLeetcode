#include <bits/stdc++.h>

using namespace std;

// 幂运算转换

// 实现将一个整数的幂运算，转换为质数的乘运算，质数按从小到大排序。
// 质数是指在大于1的自然数中，除了1和它本身以外不再有其他因数的自然数。

// 输入：
// 整数的幂运算连乘表达式，表达式中只有乘和幂运算，其中∗表示乘运算，^表示幂运算
// 整数的范围: [1,100000]
// 指数的范围:[1,100]
// 输入为一个合法的表达式，表达式最长为1000个字符。

// 输出：
// 转换为质数的乘运算，质数按从小到大排序。
// 测试用例保证，输出最长不超过100000

// Example：
// 6^3*10
// 2*2*2*2*3*3*3*5

// Idea：
// 1. 分解整数为质因子
// 2. 处理幂运算
// 3. 解析表达式
// 4. 排序输出

// 直接把所有素数拿出来

vector<int> sieve_primes(int limit)
{
    vector<bool> sieve(limit + 1, true);

    sieve[0] = sieve[1] = false;  // 0/1不是素数

    for (int i = 2; i * i <= limit; i++) {
        if (sieve[i]) {
            // 为什么从i*i开始？
            // 小于i*i的倍数已在之前的迭代中被标记
            for (int j = i * i; j <= limit; j += i) {
                sieve[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i <= limit; i++) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

// 质因子分解
vector<int> prime_factors(int n, const vector<int>& primes)
{
    vector<int> factors;

    for (int prime : primes) {
        if (prime * prime > n) {
            break;
        }

        while (n % prime == 0) {
            factors.push_back(prime);
            n /= prime;
        }
    }

    if (n > 1) {
        factors.push_back(n);
    }

    return factors;
}

// 解析表达式
vector<int> parse_expression(const string&      expression,
                             const vector<int>& primes)
{
    vector<int>  total_factors;
    stringstream ss(expression);
    string       term;

    while (getline(ss, term, '*')) {
        if (term.find('^') != string::npos) {
            int    base;
            int    exp;
            size_t pos = term.find('^');
            base       = stoi(term.substr(0, pos));
            exp        = stoi(term.substr(pos + 1));

            vector<int> factors = prime_factors(base, primes);
            for (int i = 0; i < exp; i++) {
                total_factors.insert(total_factors.end(), factors.begin(),
                                     factors.end());
            }
        }
        else {
            int         base    = stoi(term);
            vector<int> factors = prime_factors(base, primes);

            total_factors.insert(total_factors.end(), factors.begin(),
                                 factors.end());
        }
    }

    return total_factors;
}

int main()
{
    string expression;
    cin >> expression;

    int         limit  = 100007;
    vector<int> primes = sieve_primes(limit);

    vector<int> factors = parse_expression(expression, primes);

    sort(factors.begin(), factors.end());
    for (size_t i = 0; i < factors.size(); i++) {
        cout << factors[i];
        if (i != factors.size() - 1) {
            cout << "*";
        }
    }
    cout << endl;

    return 0;
}