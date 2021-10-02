#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod=1e9+7;
int lengthOfLongestSubstring(string s){
    unordered_map<char,int> mp;
    int t=0;
    int l=0;
    int r=0;
    while(r<s.size()){
        if(mp.find(s[r])!=mp.end()){
            l=max(mp[s[r]]+1,l);
        }
        t=max(t,r-l+1);
        mp[s[r]]=r;
        r+=1;
    }
    return t;
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
        cout<<lengthOfLongestSubstring(s)<<endl;
    }
    return 0;
}
