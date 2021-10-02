#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string printlcs(string x, string y){
    int i,j;
    int n=x.size();
    int m=y.size();
    int dp[n+1][m+1];
    for(i=0;i<n+1;i++){
        for(j=0;j<m+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(i=1;i<n+1;i++){
        for(j=1;j<m+1;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    string s;
    i=n,j=m;
    while(i>0 and j>0){
        if(x[i-1]==y[j-1]){
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
    return(s);
}
int lcs(string x, string y){
    int i,j;
    int n=x.size();
    int m=y.size();
    int dp[n+1][m+1];
    for(i=0;i<n+1;i++){
        for(j=0;j<m+1;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(i=1;i<n+1;i++){
        for(j=1;j<m+1;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return(dp[n][m]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        string s,t;
        cin>>s;
        t=s;
        reverse(s.begin(),s.end());
        int c=lcs(s,t);
        string p=printlcs(s,t);
        cout<<c<<endl;
        cout<<p<<endl;
    }
    return 0;
}
