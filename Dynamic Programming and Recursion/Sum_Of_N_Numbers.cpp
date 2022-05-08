#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int i;
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>dp(1000);
    dp[0]=0;
    i=0;
    while(i<n){
        dp[i+1]=a[i]+dp[i];
        i+=1;
    }
    for(i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    return 0;
}
