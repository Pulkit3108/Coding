#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool isAnagram(string a, string b){
    int f[26]={0};
    if(a.size()!=b.size()){
        return 0;
    }
    for(auto it:a){
        f[it-'a']+=1;
    }
    for(auto it:b){
        f[it-'a']-=1;
    }   
    for(int i=0;i<26;i++){
        if(f[i]>0){
            return false;
        }
    }
    return true;
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
        cout<<isAnagram(s,t)<<endl;
    }
    return 0;
}
