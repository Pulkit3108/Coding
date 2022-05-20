#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int mod = 1e9 + 7;
int binaryExponentiation(int a, int b, int m)
{
    int t = 1;
    while (b)
    {
        if (b & 1)
        {
            t = (t * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return t;
}
ll multiplicativeInverse(int a, int M)
{
    return binaryExponentiation(a, M - 2, M);
}
int binaryMultiplication(int a, int b)
{
    int x = 0;
    while (b)
    {
        if (b & 1)
        {
            x = (x + 0LL + a) % mod;
        }
        a = (a + 0LL + a) % mod;
        b = b >> 1;
    }
    return x;
}
int binaryExponentiationRecursive(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    int x = binaryExponentiationRecursive(a, b / 2);
    if (b & 1)
    {
        return (a * (x * 1LL * x) % mod) % mod;
    }
    else
    {
        return (x * 1LL * x) % mod;
    }
}
int binaryExponentiationIterative(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1)
        {
            x = binaryMultiplication(x, a) % mod;
        }
        a = binaryMultiplication(a, a) % mod;
        b = b >> 1;
    }
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin >> T;
    while (T--)
    {
        cout << binaryExponentiationRecursive(2, 13) << endl;
        cout << binaryExponentiationIterative(2, 10) << endl;
    }
    return 0;
}
