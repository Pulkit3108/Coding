#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool recur(string s,unordered_set<string> &d,vector<int> &t,int id){
    if(id==s.size()){
        return true;
    }
    if(t[id]!=-1){
        return t[id];
    }
    for(int i=id+1;i<s.size()+1;i++){
        if(d.find(s.substr(id,i-id))!=d.end() && recur(s,d,t,i)){
            t[id]=1;
            return true;
        }
    }
    t[id]=0;
    return false;
}
bool wordBreak(string s, vector<string>& wordDict){
    unordered_set<string> d(wordDict.begin(),wordDict.end());
    vector<int> t(s.size(),-1);
    return recur(s,d,t,0);
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
        int n;
        cin>>n;
        vector<string> d(n);
        for(int i=0;i<n;i++){
            cin>>d[i];
        }
        cout<<wordBreak(s,d)<<endl;
    }
    return 0;
}
