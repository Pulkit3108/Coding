#include<bits/stdc++.h>
using namespace std;
#define ll long long int
static int dp[1001][1001];
int mcm(int a[],int i,int j){
    int k;
    int m=INT_MAX;
    if(dp[i][j]!=-1){
        return(dp[i][j]);
    }
    if(i==j){
        return 0;
    }
    for(k=i;k<j;k++){
        int l,r;
        if(dp[i][k]!=-1){
            l=dp[i][k];
        }
        else{
            l=mcm(a,i,k);
        }
        if(dp[k+1][j]!=-1){
            r=dp[k+1][j];
        }
        else{
            r=mcm(a,k+1,j);
        }
        int t=l+r+a[i-1]*a[k]*a[j];
        // int t=mcm(a,i,k)+mcm(a,k+1,j)+(a[i-1]*a[k]*a[j]);
        m=min(m,t);
    }
    dp[i][j]=m;
    return(dp[i][j]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,i;
        cin>>n;
        int a[n];
        memset(dp,-1, sizeof(dp));
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        int c=mcm(a,1,n-1);
        cout<<c<<endl;
    }
    return 0;
}
