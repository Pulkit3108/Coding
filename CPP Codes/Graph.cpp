#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
const int inf = 1e9 + 7;
const int N = 1e5 + 7;
bool vis[N];
void bfs()
{
    queue<int> q;
    q.push(1);
    vis[1] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int i = 0; i < v[u].size(); i++)
        {
            if (!vis[v[u][i]])
            {
                vis[v[u][i]] = true;
                q.push(v[u][i]);
            }
        }
    }
    cout << endl;
}
void dfs(int u)
{
    cout << u << " ";
    vis[u] = true;
    for (int i = 0; i < v[u].size(); i++)
    {
        if (!vis[v[u][i]])
        {
            dfs(v[u][i]);
        }
    }
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
        int n, m;
        cin >> n >> m;
        cout << "ADJACENCY MATRIX" << endl;
        vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            a[x][y] = 1;
            a[y][x] = 1;
        }
        vector<int> v[n];
        cout << "ADJACENCY LIST" << endl;
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
    }
    return 0;
}