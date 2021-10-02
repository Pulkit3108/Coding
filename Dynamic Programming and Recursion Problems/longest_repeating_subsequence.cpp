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
        string x;
        cin>>x;
        int n=x.size();
        int dp[n+1][n+1];
        int i,j;
        for(i=0;i<n+1;i++){
            for(j=0;j<n+1;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(i=1;i<n+1;i++){
            for(j=1;j<n+1;j++){
                if(x[i-1]==x[j-1] && i!=j){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string s;
        i=n,j=n;
        while(i>0 && j>0){
            if(x[i-1]==x[j-1] && i!=j){
                s.push_back(x[i-1]);
                i-=1;
                j-=1;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    i-=1;
                }
                else{
                    j-=1;
                }
            }
        }
        reverse(s.begin(),s.end());
        cout<<s<<endl;
        cout<<dp[n][n]<<endl;
    }
    return 0;
}
