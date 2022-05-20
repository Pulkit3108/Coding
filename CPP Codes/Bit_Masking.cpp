#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<int>> subsets(vector<int> &nums)
{
    int ct = (1 << nums.size()) - 1;
    int i, j;
    vector<vector<int>> x;
    for (i = 0; i < ct + 1; i++)
    {
        vector<int> s;
        for (j = 0; j < nums.size(); j++)
        {
            if ((i & (1 << j)) != 0)
            {
                s.push_back(nums[j]);
            }
        }
        x.push_back(s);
    }
    return x;
}
void printBinary(int n)
{
    for (int i = 10; i > -1; i--)
    {
        cout << (((n >> i)) & 1);
    }
    cout << endl;
}
bool findSetBit(int n, int i)
{
    if ((n & (1 << i)) != 0)
    {
        cout << "Set Bit";
        return true;
    }
    else
    {
        cout << "Not Set Bit";
        return false;
    }
}
int setBit(int n, int i)
{
    return (n | 1 << i);
}
int unsetBit(int n, int i)
{
    return (n & (~(1 << i)));
}
int toggleBit(int n, int i)
{
    return (n ^ (1 << i));
}
int countSetBits(int n)
{
    int c = 0;
    for (int i = 31; i > -1; i--)
    {
        if ((n & (1 << i)) != 0)
        {
            c += 1;
        }
    }
    cout << "SetBits in ";
    printBinary(n);
    cout << " : " << c << endl;
    return c;
}
int divideBy2(int n)
{
    return n >> 1;
}
int multiplyBy2(int n)
{
    return n << 1;
}
bool checkEvenOdd(int n)
{
    if ((n & 1) == 0)
    {
        cout << "Even" << endl;
        return true;
    }
    else
    {
        cout << "Odd" << endl;
        return false;
    }
}
// 1<<5 == ' '
char upperToLowerCase(char c)
{
    return c | 1 << 5;
}
// ~(1<<5) == ' '
char lowerToUpperCase(char c)
{
    return c & ~(1 << 5);
}
int clearLSB(int n, int i)
{
    return n & (~((1 << (i + 1)) - 1));
}
int clearMSB(int n, int i)
{
    return n & ((1 << (i + 1)) - 1);
}
bool checkPowerOf2(int n)
{
    return !(n & (n - 1));
}
void swap(int &a, int &b)
{
    a = a ^ b;
    b = b ^ a;
    a = a ^ b;
}
int oddCountElement(vector<int> &a)
{
    int x = 0;
    for (auto it : a)
    {
        x = x ^ it;
    }
    return (x);
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
        cout << __builtin_popcount(10) << endl;
        cout << __builtin_popcountll((1LL << 32) - 1) << endl;
        int n;
        cin >> n;
        vector<int> a(n);
        int i;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }
    return 0;
}
