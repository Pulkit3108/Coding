#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void generatebinary(int n,int o,int z,string t,vector<string> &r){
    if(n==0){
        r.push_back(t);
        return;
    }
    string t1=t;
    t1.push_back('1');
    generatebinary(n-1,o+1,z,t1,r);
    if(o>z){
        string t2=t;
        t2.push_back('0');
        generatebinary(n-1,o,z+1,t2,r);
    }
}
vector<string> NBitBinary(int n){
    vector<string> r;
    string t="";
    generatebinary(n,0,0,t,r);
    return r;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<string> s=NBitBinary(n);
        for(int i=0;i<s.size();i++){
            cout<<s[i]<<" ";
        }
        
    }
    return 0;
}
