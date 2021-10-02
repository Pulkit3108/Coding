#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void lettercase(string s,string t,vector<string> &r){
    if(s.size()==0){
        r.push_back(t);
        return;
    }
    if(isdigit(s[0])){
        t.push_back(s[0]);
        s.erase(s.begin());
        lettercase(s,t,r);
    }
    else{
        string t1=t;
        string t2=t;
        t1.push_back(toupper(s[0]));
        t2.push_back(tolower(s[0]));
        s.erase(s.begin());
        lettercase(s,t1,r);
        lettercase(s,t2,r);
    }
}
vector<string> letterCasePermutation(string s) {
    vector<string> r;
    string t="";
    lettercase(s,t,r);
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
        vector<string> m=letterCasePermutation(s);
        for(int i=0;i<m.size();i++){
            cout<<m[i]<<" ";
        }
    }
    return 0;
}
