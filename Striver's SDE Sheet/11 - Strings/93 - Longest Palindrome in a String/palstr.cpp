#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string longestPalin(string s){
    int n=s.size();
    bool dp[n][n];
    int l=0;
    int r=-1;
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g==0){
                dp[i][j]=true;
            }
            else if(g==1){
                if(s[i]==s[j]){
                    dp[i][j]=true;
                }
                else{
                    dp[i][j]=false;
                }
            }
            else{
                if(s[i]==s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                }
                else{
                    dp[i][j]=false;
                }
            }
            if(dp[i][j] && (j-i)>(r-l)){
                l=i;
                r=j;
            }
        }
    }
    return s.substr(l,r-l+1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        string s;
        cin>>s;
        cout<<longestPalin(s)<<endl;
    }
    return 0;
}
