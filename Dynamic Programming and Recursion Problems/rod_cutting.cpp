#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int cutRod(int price[], int n) {
    int i,j;
    int dp[n+1][n+1];
    for(i=0;i<n+1;i++){
        for(j=0;j<n+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(i=1;i<n+1;i++){
        for(j=1;j<n+1;j++){
            if(i<=j){
                dp[i][j]=max(price[i-1]+dp[i][j-i],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return(dp[n][n]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,i,j,N;
        cin>>n;
        int len[n],pr[n];
        for(i=0;i<n;i++){
            cin>>pr[i];
        }
        for(i=0;i<n;i++){
            cin>>len[i];
        }
        cin>>N;
        int dp[n+1][N+1];
        for(i=0;i<n+1;i++){
            for(j=0;j<N+1;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(i=1;i<n+1;i++){
            for(j=1;j<N+1;j++){
                if(len[i-1]<=j){
                    dp[i][j]=max(pr[i-1]+dp[i][j-len[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        cout<<dp[n][N]<<endl;
    }
    return 0;
}
