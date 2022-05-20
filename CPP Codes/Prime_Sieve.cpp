#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1e5 + 10;
// Check Prime
vector<int> isPrime(N, 1);
// Lowest and Highest Prime that divide N
vector<int> lowestPrime(N, 0), highestPrime(N, 0);
// Prime Factors
vector<int> pm;
unordered_map<int, int> mp;
// Divisors
vector<int> d[N];
void SieveOfEratosthenes(int n)
{
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i < n; i++)
    {
        if (isPrime[i])
        {
            lowestPrime[i] = highestPrime[i] = i;
            for (int j = 2 * i; j < n; j += i)
            {
                isPrime[j] = 0;
                highestPrime[j] = i;
                if (lowestPrime[j] == 0)
                {
                    lowestPrime[j] = i;
                }
            }
        }
    }
}
void primeFactors(int n)
{
    while (n > 1)
    {
        int f = highestPrime[n];
        while (n % f == 0)
        {
            n /= f;
            pm.push_back(f);
            ++mp[f];
        }
    }
}
void divisors(int n)
{
    for (int i = 2; i < n; i++)
    {
        for (int j = i; j < n; j += i)
        {
            d[j].push_back(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    // cin>>T;
    while (T--)
    {
        int n;
        cin >> n;
    }
    return 0;
}
