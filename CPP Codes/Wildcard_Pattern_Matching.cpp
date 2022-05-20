#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        string s,p;
        cin>>p>>s;
        int i,j;
        int n=s.size();
        int m=p.size();
        int dp[n+1][m+1];
        for(i=0;i<n+1;i++){
            for(j=0;j<m+1;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
                if(i==0 && j==0){
                    dp[i][j]=1;
                }
                if(j>0 && p[j-1]=='*'){
                    dp[0][j]=dp[0][j-1];
                }
            }
        }
        for(i=1;i<n+1;i++){
            for(j=1;j<m+1;j++){
                if(p[j-1]=='?' || p[j-1]==s[i-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j]=dp[i][j-1] || dp[i-1][j];
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        if(dp[n][m]){
            cout<<"Pattern Matched"<<endl;
        }
        else{
            cout<<"Pattern didn't Matched"<<endl;
        }
    }
    return 0;
}
