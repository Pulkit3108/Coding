#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool ispali(string s,int l,int r){
    while(l<=r){
        if(s[l]!=s[r]){
            return false;
        }
        l+=1;
        r-=1;
    }
    return true;
}
void recur(string s,vector<vector<string>> &t,vector<string> &p,int id){
    if(id==s.size()){
        t.push_back(p);
        return;
    }
    for(int i=id;i<s.size();i++){
        if(ispali(s,id,i)){
            p.push_back(s.substr(id,i-id+1));
            recur(s,t,p,i+1);
            p.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> t;
    vector<string> p;
    recur(s,t,p,0);
    return t;
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
        vector<vector<string>> b=partition(s);
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[i].size();j++){
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
