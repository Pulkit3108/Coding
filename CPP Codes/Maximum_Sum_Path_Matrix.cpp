#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        int a[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        int dp[n][m];
        for(int j=0;j<m;j++){
            dp[0][j]=a[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(j>0 and j<m-1){
                    dp[i][j]=a[i][j]+max(dp[i-1][j-1],dp[i-1][j+1]);
                }
                else if(j>0){
                    dp[i][j]=a[i][j]+dp[i-1][j-1];
                }
                else if(j<m-1){
                    dp[i][j]=a[i][j]+dp[i-1][j+1];
                }
            }
        }
        int mx=INT_MIN;
        for(int j=0;j<m;j++){
            mx=max(mx,dp[n-1][j]);
        }
        cout<<mx<<endl;
    }
    return 0;
}
