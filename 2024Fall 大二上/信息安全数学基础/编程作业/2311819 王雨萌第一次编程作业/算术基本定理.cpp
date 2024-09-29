#include <iostream>
#include <vector>
#include <cmath>

/*
算术基本定理分解程序
支持n在 0~1000000中计算
目前支持单次运算

Version：1.0
Author：王雨萌
*/

using namespace std;
vector<int> prime;
bool is_prime[1000010];

void Eratosthenes(int n)
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; ++i)
        is_prime[i] = true;
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            prime.push_back(i);
            if ((long long)i * i > n)
                continue;
            for (int j = i * i; j <= n; j += i)
                // 因为从 2 到 i - 1 的倍数我们之前筛过了，这里直接从 i
                // 的倍数开始，提高了运行速度
                is_prime[j] = false; // 是 i 的倍数的均不是素数
        }
    }
}

bool is_in[1000010];
int cishu[1000010] = {0};

void depart(int num, int a)
{
    Eratosthenes(a);
    for (int i = 2; i <= a; i++)
    {
        if (is_prime[i])
        {
            if (num % i == 0)
            {
                is_in[i] = true;
                while (num % i == 0)
                {
                    num = num / i;
                    cishu[i]++;
                }
            }
        }
    }
}

int main()
{
    cout << "Please input n(n>0): ";
    int n, half = sqrt(n), cut = 0;
    cin >> n;
    depart(n, half);
    cout << n << "=";
    for (int i = 2; i <= half; i++)
    {
        if (is_in[i])
        {
            if (cut++)
                cout << "*";
            cout << i << "^" << cishu[i];
        }
    }
}