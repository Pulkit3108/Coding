#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void generatepermutation(string s,string t,vector<string> &r){
    if(s.size()==0){
        r.push_back(t);
        return;
    }
    string n=t;
    n.push_back(' ');
    n.push_back(s.front());
    t.push_back(s.front());
    s.erase(s.begin());
    generatepermutation(s,t,r);
    generatepermutation(s,n,r);
}
vector<string> permutation(string S){
    vector<string> r;
    string t="";
    t.push_back(S.front());
    S.erase(S.begin());
    generatepermutation(S,t,r);
    sort(r.begin(),r.end());
    return r;
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
        vector<string> p=permutation(s);
        for(int i=0;i<p.size();i++){
            cout<<p[i]<<" ";
        }
    }
    return 0;
}
