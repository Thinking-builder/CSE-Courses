#include <iostream>

/*
扩展欧几里得算法计算乘法逆元
+ 函数模块：
  - Lcm：最小公倍数求解函数；
  - Gcd：最大公因数求解函数；
  - Ep：扩展欧几里得算法；

Version：1.0
Author：王雨萌

*/
long long Format(int m, long long num)
{
    if (num < 0)
    {
        return num + m;
    }
    else
    {
        return num;
    }
}

long long Gcd(long long a, long long b)
{
    if (a < b) // 令a一定大于等于b
    {
        int temp = a;
        a = b;
        b = temp;
    }
    int r = a % b;
    while (r != 0)
    {
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

long long Lcm(long long a, long long b)
{
    return (a * b) / Gcd(a, b);
}

int s0 = 1, s1 = 0, s;
int t0 = 0, t1 = 1, t;

long long Ep(int a, int m) // 详细推导一下这个整个过程
{
    if (a > m)
    {
        long long q = 1; // 初始化，使之进入

        while (q != 0 ) // 为什么在这里截止：当r_{n+1} = 0时候，q_{n} = r_{n-1}/rn,正好计算完成
        {
            if (m == 0)
                return s0;
            else
                q = a / m; // q_i = r_{i-1}/r_i
            long long temp = m;
            m = a % temp;
            a = temp;

            s = s0 - s1 * q; // q -> q_i
            s0 = s1;
            s1 = s;
        }
        return s;
    }
    else
    {
        int temp = a;
        a = m;
        m = temp;

        long long q = 1; // 初始化，使之进入

        while (q != 0 ) // 为什么在这里截止：当r_{n+1} = 0时候，q_{n} = r_{n-1}/rn,正好计算完成
        {
            if (m == 0)
                return t0;
            else 
                q = a / m; // q_i = r_{i-1}/r_i
            long long temp = m;
            m = a % temp;
            a = temp;

            t = t0 - t1 * q; // q -> q_i
            t0 = t1;

            t1 = t;
        }
        return t;
    }
}

using namespace std;

int main()
{
    int a = 0, b = 0;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "Gcd(a,b) = " << Gcd(a, b) << endl;
    cout << "Lcm(a,b) = " << Lcm(a, b) << endl;
    cout << "a^(-1) = " << Format(b,Ep(a, b)) << "(mod " << b << ")" << endl;
    cout << "b^(-1) = " << Format(a,Ep(b, a)) << "(mod " << a << ")" << endl;
    system("pause");
}
