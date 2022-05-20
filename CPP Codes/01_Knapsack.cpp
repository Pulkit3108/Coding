#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int v[n],w[n];
    int i,j;
    for(i=0;i<n;i++){
        cin>>v[i];
    }
    for(i=0;i<n;i++){
        cin>>w[i];
    }
    int W;
    cin>>W;   
    int dp[n+1][W+1];
    memset(dp,0,sizeof(dp[0][0])*(n+1)*(W+1));
    for(i=1;i<=n;i++){ 
        for(j=1;j<=W;j++){ 
            if(w[i-1]<=j){ 
                dp[i][j]=max(v[i-1]+dp[i-1][j-w[i-1]],dp[i-1][j]);
            } 
            else{
                dp[i][j]=dp[i-1][j]; 
            }
        } 
    } 
    cout<<dp[n][W];
    return 0; 
} 
