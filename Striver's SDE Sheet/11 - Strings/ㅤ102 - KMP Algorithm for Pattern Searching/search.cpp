#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int p=1e9+7;
vector<int> lps(string s) {
    vector<int> ps(s.size(),0);
    int j=0;
    int i=1;
    while(i<s.size()){
        if(s[i]==s[j]){
            j+=1;
            ps[i]=j;
            i+=1;
        }
        else{
            if(j!=0){
                j=ps[j-1];
            }
            else{
                ps[i]=0;
                i+=1;
            }
        }
    }
    return ps;
}
vector<int> KMPSearch(string pattern,string text){
    vector<int> ps=lps(pattern);
    int i=0;
    int j=0;
    vector<int> s;
    while(i<text.size()) {
        if(pattern[j]==text[i]){
            j+=1;
            i+=1;
        }
        if(j==pattern.size()) {
            s.push_back(i-j);
            j=ps[j - 1];
        }
        else if(i<text.size() && pattern[j]!=text[i]){
            if(j!=0){
                j=ps[j-1];
            }
            else{
                i=i+1;
            }
        }
    }
    return s;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        string s,t;
        cin>>s>>t;
        vector<int> a=KMPSearch(s,t);
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
