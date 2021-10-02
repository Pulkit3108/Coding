#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string reverseWords(string s) { 
    vector<string> r;
    string t="";
    for(int i=0;i<s.size();i++){
        if(s[i]=='.'){
            r.push_back(t);
            t="";
        }
        else{
            t+=s[i];
        }
    }
    r.push_back(t);
    reverse(r.begin(),r.end());
    t.clear();
    for(int i=0;i<r.size();i++){
        t+=r[i];
        t.push_back('.');
    }
    t.erase(t.end()-1);
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
        cout<<reverseWords(s)<<endl;
    }
    return 0;
}
