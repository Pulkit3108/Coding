/*
Longest Common Subsequence
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string x,y;
    cin>>x>>y;
    int n=x.length();
    int m=y.length();
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp[0][0])*(n+1)*(m+1));
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}
