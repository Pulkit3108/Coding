#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int maximumPath(int n, vector<vector<int>> Matrix){
    int dp[n][n];
    for(int j=0;j<n;j++){
        dp[0][j]=Matrix[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>0 && j<n-1){
                dp[i][j]=Matrix[i][j]+max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]));
            }
            else if(j>0){
                dp[i][j]=Matrix[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
            }
            else if(j<n-1){
                dp[i][j]=Matrix[i][j]+max(dp[i-1][j],dp[i-1][j+1]);
            }
            else{
                dp[i][j]=Matrix[i][j]+dp[i-1][j];
            }
        }
    }
    int m=INT_MIN;
    for(int j=0;j<n;j++){
        m=max(m,dp[n-1][j]);
    }
    return m;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<vector<int>> a;
        for(int i=0;i<n;i++){
            vector<int> t(n);
            for(int j=0;j<n;j++){
                cin>>t[j];
            }
            a.push_back(t);
        }
        cout<<maximumPath(n,a)<<endl;
        
    }
    return 0;
}
