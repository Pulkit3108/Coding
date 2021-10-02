#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int minimumNumberOfDeletions(string S){ 
    string T=S;
    reverse(S.begin(),S.end());
    int i,j;
    int n=S.size();
    int dp[n+1][n+1];
    for(i=0;i<n+1;i++){
        for(j=0;j<n+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(i=1;i<n+1;i++){
        for(j=1;j<n+1;j++){
            if(S[i-1]==T[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return(n-dp[n][n]);
} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        cout<<minimumNumberOfDeletions(s);
    }
    return 0;
}
