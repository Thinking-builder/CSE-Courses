#include <iostream>
#include <vector>

/*
Eratosthenes-Sieve:
筛选质因数的方法

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

int main()
{
    cout << "Please input the range:1- ";
    int range;
    cin >> range;
    cout << "--------------------------------------------" << endl;

    Eratosthenes(range);
    for (int i = 2; i <= range; i++)
    {
        if (is_prime[i] == true)
            cout << i << " ";
    }
    return 0;
}