#include<bits/stdc++.h>
using namespace std;
#define ll long long int
long countWaysToMakeChange(int *denominations, int n, int value){
    long dp[n+1][value+1];
    for(int j=0;j<value+1;j++){
        dp[0][j]=0;
    }
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<value+1;j++){
            if(denominations[i-1]<=j){
                dp[i][j]=dp[i][j-denominations[i-1]]+dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][value];
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
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int v;
        cin>>v;
        cout<<countWaysToMakeChange(a,n,v)<<endl;
    }
    return 0;
}
