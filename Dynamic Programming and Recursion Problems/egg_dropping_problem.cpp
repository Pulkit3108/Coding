#include<bits/stdc++.h>
using namespace std;
#define ll long long int
static int dp[1001][1001];
int eggdrop(int n, int k){
    if(n<2 || k==1){
        return(n);
    }
    if(dp[n][k]!=-1){
        return(dp[n][k]);
    }
    int i;
    int m=INT_MAX;
    for(i=1;i<n+1;i++){
        int l,h;
        if(dp[i-1][k-1]!=-1){
            l=dp[i-1][k-1];
        }
        else{
            l=eggdrop(i-1,k-1);
        }
        if(dp[n-i][k]!=-1){
            h=dp[n-i][k];
        }
        else{
            h=eggdrop(n-i,k);
        }
        int t=1+max(l,h);
        m=min(m,t);
    }
    dp[n][k]=m;
    return(m);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        memset(dp,-1,sizeof(dp));
        cout<<eggdrop(n,k)<<endl;
    }
    return 0;
}
