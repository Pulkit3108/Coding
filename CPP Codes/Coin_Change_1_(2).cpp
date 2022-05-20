#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,i,j;
    cin>>n;
    int C[n];
    for(i=0;i<n;i++){
        cin>>C[i];
    }
    int t;
    cin>>t;
    int dp[t+1];
    dp[0]=0;    
    for(i=1;i<=t;i++){
        dp[i]=INT_MAX;
        int p=INT_MAX;
        for(j=0;j<n;j++){
            if(i-C[j]>=0){
                p=dp[i-C[j]];
            }
            if(p!=INT_MAX){
                dp[i]=min(dp[i],p+1);
            }
        }
    }
    cout<<dp[t];
    return 0; 
} 
