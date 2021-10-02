#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int longestCommonSubsequence(string text1, string text2){
    int n=text1.size();
    int m=text2.size();
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<m+1;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];     
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        string x,y;
        cin>>x>>y;
        cout<<longestCommonSubsequence(x,y);
    }
    return 0;
}
