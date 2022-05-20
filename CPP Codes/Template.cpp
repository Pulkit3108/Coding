#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
const ll N = 1e5 + 10;
const ll inf = 1e9 + 10;
const ll MOD = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // ignore /n
    //  cin.ignore();
    //  #ifndef ONLINE_JUDGE
    //      freopen("input.txt", "r", stdin);
    //      freopen("output.txt", "w", stdout);
    //  #endif
    ll T = 1;
    // cin>>T;
    while (T--)
    {
        double a = 10000;
        double b = 10000;
        cout << setprecision(2) << fixed << a * b << endl;
        // To input complete line;
        string s;
        getline(cin, s);
        cout << s << endl;
    }
#ifndef ONLINE_JUDGE
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}