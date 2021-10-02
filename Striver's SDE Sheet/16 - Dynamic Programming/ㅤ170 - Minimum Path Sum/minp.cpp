#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int minPathSum(vector<vector<int>>& grid){
    int n=grid.size();
    int m=grid[0].size();
    int dp[n][m];
    dp[0][0]=grid[0][0];
    for(int i=1;i<n;i++){
        dp[i][0]=dp[i-1][0]+grid[i][0];
    } 
    for(int j=1;j<m;j++){
        dp[0][j]=dp[0][j-1]+grid[0][j];
    }    
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n-1][m-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a;
        for(int i=0;i<n;i++){
            vector<int> t(m);
            for(int j=0;j<m;j++){
                cin>>t[j];
            }
            a.push_back(t);
        }
        cout<<minPathSum(a)<<endl;
    }
    return 0;
}
