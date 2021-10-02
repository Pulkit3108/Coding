#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int static dp[1005][1005];
int lcs(string x,string y,int n,int m){
    if(n==0 || m==0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return(dp[n][m]);
    }
    if(x[n-1]==y[m-1]){
        dp[n][m]=1+lcs(x,y,n-1,m-1);
        return(dp[n][m]);
    }
    else{
        dp[n][m]=max(lcs(x,y,n,m-1),lcs(x,y,n-1,m));
        return(dp[n][m]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,m;
        memset(dp,-1, sizeof(dp));
        string x,y;
        cin>>n>>m;
        cin>>x>>y;
        int c=lcs(x,y,n,m);
        cout<<c<<endl;
    }
    return 0;
}
