#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<string> AllPossibleStrings(string s){
    vector<string> r;
    for(int i=1;i<(1<<s.size());i++){
        string t;
        for(int j=0;j<s.size();j++){
            if(i & (1<<j)){
                t.push_back(s[j]);
            }
        }
        r.push_back(t);
    }
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
        vector<string> t=AllPossibleStrings(s);
        for(int i=0;i<t.size();i++){
            cout<<t[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
