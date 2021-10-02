#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int countPalindrome(string s) {
    int n=s.size();
    int i,j,k;
    int c=0;
    bool dp[n][n];
    for(i=0;i<n;i++){
        for(j=0,k=i;j<n;j++,k++){
            if(i==0){
                dp[j][k]=true;
                c+=1;
            }
            else if(i==1){
                if(s[j]==s[k]){
                    dp[j][k]=true;
                    c+=1;
                }
                else{
                    dp[j][k]=false;
                }
            }
            else{
                if(s[j]==s[k] and dp[j+1][k-1]){
                    dp[j][k]=true;
                    c+=1;
                }
                else{
                    dp[j][k]=false;
                }
            }
        }
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
        cout<<countPalindrome(s)<<endl;
    }
    return 0;
}
