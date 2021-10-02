#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int p=1e9+7;
int search(string pattern,string text){
    ll hp=0;
    ll ht=0;
    ll d=26;
    for(ll i=0;i<pattern.size();i++){
        hp*=d;
        ht*=d;
        hp=hp+((pattern[i]-'A'+1)%p);
        ht=ht+((text[i]-'A'+1)%p);
    }
    for(ll i=0;i<text.size()-pattern.size()+1;i++){
        if(hp==ht){
            bool flag=true;
            for(ll j=0;j<pattern.size();j++){
                if(text[i+j]!=pattern[j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                return i;
            }
        }
        if(i<text.size()-pattern.size()){
            ht=ht-(((text[i]-'A'+1)*(ll)pow(d,pattern.size()-1))%p);
            ht=((ht*d)+(text[i+pattern.size()]-'A'+1))%p;  
        }
    }
    return -1;
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
        cout<<search(s,t)<<endl;
    }
    return 0;
}
