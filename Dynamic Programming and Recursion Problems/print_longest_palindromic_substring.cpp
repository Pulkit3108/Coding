#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string longestPalindrome(string s) {
    int n=s.size();
    int i,j,k;
    int st,ed;
    string c="";
    bool dp[n][n];
    for(i=0;i<n;i++){
        for(j=0,k=i;j<n,k<n;j++,k++){
            if(i==0){
                dp[j][k]=true;
                st=j;
                ed=k;
            }
            else if(i==1){
                if(s[j]==s[k]){
                    dp[j][k]=true;
                    st=j;
                    ed=k;
                }
                else{
                    dp[j][k]=false;
                }
            }
            else{
                if(s[j]==s[k] and dp[j+1][k-1]){
                    dp[j][k]=true;
                    st=j;
                    ed=k;
                }
                else{
                    dp[j][k]=false;
                }
            }
        }
    }
    for(i=st;i<=ed;i++){
        c+=s[i];
    }
    return c;
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
        cout<<longestPalindrome(s)<<endl;
    }
    return 0;
}
