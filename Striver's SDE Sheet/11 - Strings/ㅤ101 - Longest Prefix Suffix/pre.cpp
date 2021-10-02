#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int p=1e9+7;
int lps(string s) {
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
    return ps[s.size()-1];
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
        cout<<lps(s)<<endl;
    }
    return 0;
}
