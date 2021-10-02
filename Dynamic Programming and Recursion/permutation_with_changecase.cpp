#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void changeCase(string s,string t,vector<string> &r){
    if(s.size()==0){
        r.push_back(t);
        return;
    }
    string n=t;
    n.push_back(toupper(s.front()));
    t.push_back(tolower(s.front()));
    s.erase(s.begin());
    changeCase(s,t,r);
    changeCase(s,n,r);
}
vector<string> casePermutation(string s){
    vector<string> r;
    string t="";
    changeCase(s,t,r);
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
        vector<string> p=casePermutation(s);
        for(int i=0;i<p.size();i++){
            cout<<p[i]<<" ";
        }
    }
    return 0;
}
