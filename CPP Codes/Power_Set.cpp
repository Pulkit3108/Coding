#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void makeset(string s,string t,vector<string> &r){
    if(s.empty()){
        r.push_back(t);
        return;
    }
    string t1=t;
    string t2=t+s.front();
    s.erase(s.begin());
    makeset(s,t1,r);
    makeset(s,t2,r);
}
vector<string> powerSet(string s){
    vector<string> r;
    string t="";
    makeset(s,t,r);
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
        vector<string> v=powerSet(s);
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
    }
    return 0;
}
