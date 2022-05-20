#include <bits/stdc++.h>
using namespace std;
#define ll long long int
double eps = 1e-6;
int lowerBound(vector<int> &v, int x)
{
    int lo = 0, hi = v.size() - 1;
    int mid;
    while (hi - lo > 1)
    {
        mid = (lo + hi) / 2;
        if (v[mid] < x)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    if (v[lo] >= x)
    {
        return lo;
    }
    if (v[hi] >= x)
    {
        return hi;
    }
    return -1;
}
int upperBound(vector<int> &v, int x)
{
    int lo = 0, hi = v.size() - 1;
    int mid;
    while (hi - lo > 1)
    {
        mid = (lo + hi) / 2;
        if (v[mid] <= x)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    if (v[hi] > x)
    {
        return hi;
    }
    if (v[lo] > x)
    {
        return lo;
    }
    return -1;
}
int binarySearch(vector<int> &v, int x)
{
    int lo = 0, hi = v.size() - 1;
    int mid;
    while (hi - lo > 1)
    {
        mid = (lo + hi) / 2;
        if (v[mid] < x)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    if (v[lo] == x)
    {
        return lo;
    }
    if (v[hi] == x)
    {
        return hi;
    }
    return -1;
}
double squareRoot(double x)
{
    double lo = 1, hi = x;
    double mid;
    while (hi - lo > eps)
    {
        mid = (lo + hi) / 2;
        if (mid * mid < x)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    return hi;
}
double multiply(double a, double n)
{
    double ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * a;
    }
    return ans;
}
double nthRoot(double x, int n)
{
    double lo = 1, hi = x;
    double mid;
    while (hi - lo > eps)
    {
        mid = (lo + hi) / 2;
        if (multiply(mid, n) < x)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    return hi;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T = 1;
    // cin>>T;
    while (T--)
    {
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
