#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> lps(string s){
    vector<int> ps(s.size(),0);
    int i=1;
    int j=0;
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
int countpalin(string s){
    string t=s;
    reverse(t.begin(),t.end());
    string n=s+to_string('$')+t;
    vector<int> lp=lps(n);
    return s.size()-lp.back();
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
        cout<<countpalin(s)<<endl;
    }
    return 0;
}
