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
        int n,i,j,W;
        cin>>n;
        int wt[n],val[n];
        for(i=0;i<n;i++){
            cin>>val[i];
        }
        for(i=0;i<n;i++){
            cin>>wt[i];
        }
        cin>>W;
        int dp[n+1][W+1];
        for(i=0;i<n+1;i++){
            for(j=0;j<W+1;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(i=1;i<n+1;i++){
            for(j=1;j<W+1;j++){
                if(wt[i-1]<=j){
                    dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        cout<<dp[n][W]<<endl;
    }
    return 0;
}
