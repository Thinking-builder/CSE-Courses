#include <iostream>

/*
求解最大公因数和最小公倍数
程序支持很大的数字的运算，在1～longlong_MAX之间
运用辗转相除法以及他们之间的关联定理

Version：1.0
Author：王雨萌
*/

using namespace std;

// gcd是关键，一般来说是辗转相除法
long long Gcd(int a, int b)
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

// 利用[a,b] = ab/(a,b)
long long Lcm(int &a, int &b)
{
    return (a * b) / Gcd(a, b);
}

int main()
{
    int a, b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "gcd(a,b) = " << Gcd(a, b) << endl;
    cout << "lcm(a,b) = " << Lcm(a, b) << endl;
    return 0;
}