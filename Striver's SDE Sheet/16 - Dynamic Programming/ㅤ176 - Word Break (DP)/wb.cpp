#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int wordBreak(string A, vector<string> &B){
    int n=A.size();
    vector<int> dp(n+1,0);
    unordered_set<string> st(B.begin(),B.end());
    dp[0]=1;
    for(int i=1;i<n+1;i++){
        for(int j=i-1;j>=0;j--){
            if(dp[j] && st.find(A.substr(j,i-j))!=st.end()){
                dp[i]=1;
                break;
            }
        }
    }
    return dp[n];
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
        int n;
        cin>>n;
        vector<string> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<wordBreak(s,a)<<endl;
    }
    return 0;
}
