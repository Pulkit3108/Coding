#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,s,i,j;
        cin>>n;
        int coin[n];
        for(i=0;i<n;i++){
            cin>>coin[i];
        }
        cin>>s;
        int dp[n+1][s+1];
        for(i=0;i<n+1;i++){
            for(j=0;j<s+1;j++){
                if(i==0){
                    dp[i][j]=INT16_MAX-1;
                }
                if(i>0 and j==0){
                    dp[i][j]=0;
                }
                if(i==1 and j>0){
                    if(j%coin[i-1]==0){
                        dp[i][j]=j/coin[i-1];
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
        for(i=2;i<n+1;i++){
            for(j=1;j<s+1;j++){
                if(coin[i-1]<=j){
                    dp[i][j]=min(1+dp[i][j-coin[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        cout<<dp[n][s];
    }
    return 0;
}
