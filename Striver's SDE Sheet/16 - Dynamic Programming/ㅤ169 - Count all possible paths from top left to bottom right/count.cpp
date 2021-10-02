#include<bits/stdc++.h>
using namespace std;
#define ll long long int
long long int numberOfPaths(int n, int m){
    long long int dp[n][m];
    long long int mod=1e9+7;
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    for(int j=0;j<m;j++){
        dp[0][j]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
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
        cout<<numberOfPaths(n,m)<<endl;

        
    }
    return 0;
}
