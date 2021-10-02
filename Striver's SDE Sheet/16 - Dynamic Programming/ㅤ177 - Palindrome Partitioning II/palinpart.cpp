#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int minCut(string s){
    int n=s.size();
    bool p[n][n];
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g==0){
                p[i][j]=true;
            }
            else if(g==1){
                p[i][j]=s[i]==s[j];
            }
            else{
                if(s[i]==s[j] && p[i+1][j-1]){
                    p[i][j]=true;
                }
                else{
                    p[i][j]=false;
                }
            }
        }
    }
    int dp[n];
    dp[0]=0;
    for(int j=1;j<n;j++){
        if(p[0][j]){
            dp[j]=0;
        }
        else{
            int m=INT_MAX;
            for(int i=j;i>0;i--){
                if(p[i][j]){
                    m=min(m,dp[i-1]);
                }
            }
            dp[j]=m+1;
        }
    }
    return dp[n-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        string s;
        cin>>s;
        cout<<minCut(s)<<endl;
    }
    return 0;
}
