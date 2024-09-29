#include <iostream>

/*
平方乘算法 - 解决大整数模幂运算问题

version：4.0
Author:王雨萌

*/
int yushu = 1;
int base = 1;

long long binfastpow(int a, int n, int m)
{
    long long yushu = 1;
    long long base = a % m;
    while (n > 0)
    {
        if (n % 2 == 1)
        {                               // 如果 n 是奇数
            yushu = (yushu * base) % m; // 结果乘以当前的 base
        }
        base = (base * base) % m; // 更新 base 为 base 的平方
        n /= 2;
    }
    return yushu;
}

using namespace std;

int main()
{
    cout << "Calculate a^n(mod m)..." << endl
         << "Please input:" << endl;
    int a = 0, n = 0, m = 0;
    cout << "  a = ";
    cin >> a;
    cout << "  n = ";
    cin >> n;
    cout << "  m = ";
    cin >> m;

    base = (base * base) % m;
    cout << a << "^" << n << "(mod" << m << ") = " << binfastpow(a, n, m);
    system("pause");
}