#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int dp[1005][1005];
int knapsack(int val[],int wt[],int W,int n){
    if(n==0 || W==0){
        return(0);
    }
    if(dp[n][W]!=-1){
        return(dp[n][W]);
    }
    else if(wt[n-1]<=W){
        dp[n][W]=max(val[n-1]+knapsack(val,wt,W-wt[n-1],n-1),knapsack(val,wt,W,n-1));
        return(dp[n][W]);
    }
    dp[n][W]=knapsack(val,wt,W,n-1);
    return(dp[n][W]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,i,W,profit;
        memset(dp,-1,sizeof(dp));
        cin>>n;
        int val[n],wt[n];
        for(i=0;i<n;i++){
            cin>>val[i];
        }
        for(i=0;i<n;i++){
            cin>>wt[i];
        }
        cin>>W;
        profit=knapsack(val,wt,W,n);
        cout<<profit<<endl;
    }
    return 0;
}
