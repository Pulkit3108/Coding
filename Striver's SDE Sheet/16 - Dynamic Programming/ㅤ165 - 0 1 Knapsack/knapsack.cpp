#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w){
    int dp[n+1][w+1];
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<w+1;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            if(weights[i-1]<=j){
                dp[i][j]=max(values[i-1]+dp[i-1][j-weights[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        int n,i,W,profit;
        cin>>n;
        vector<int> val(n);
        vector<int> wt(n);
        for(i=0;i<n;i++){
            cin>>val[i];
        }
        for(i=0;i<n;i++){
            cin>>wt[i];
        }
        cin>>W;
        profit=maxProfit(val,wt,n,W);
        cout<<profit<<endl;
    }
    return 0;
}
