#include<bits/stdc++.h>
using namespace std;
#define ll long long int
static int dp[1001][1001];
bool ispalindrome(string s,int i,int j){
    if(i==j){
        return true;
    }
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i+=1;
        j-=1;
    }
    return true;
}
int palindromicPartition(string s,int i,int j){
    if(dp[i][j]!=-1){
        return(dp[i][j]);
    }
    if(i==j || ispalindrome(s,i,j)){
        return 0;
    }
    int k;
    int m=INT_MAX;
    for(k=i;k<j;k++){
        int t=1+palindromicPartition(s,i,k)+palindromicPartition(s,k+1,j);
        m=min(m,t);
    }
    dp[i][j]=m;
    return(dp[i][j]);
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
        memset(dp,-1, sizeof(dp));
        cout<<palindromicPartition(s,0,s.size()-1)<<endl;
    }
    return 0;
}
