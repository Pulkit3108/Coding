#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int minDistance(string word1, string word2){
    int n=word1.size();
    int m=word2.size();
    int dp[n+1][m+1];
    for(int i=0;i<n+1;i++){
        dp[i][0]=i;
    }
    for(int j=0;j<m+1;j++){
        dp[0][j]=j;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(word1[i-1]==word2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
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
        string s1,s2;
        cin>>s1>>s2;
        cout<<minDistance(s1,s2);
    }
    return 0;
}
