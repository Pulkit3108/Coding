#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int romanToDecimal(string &str) {
    unordered_map<char,int> mp={
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };
    int n=0;
    for(int i=0;i<str.size()-1;i++){
        if(mp[str[i]]<mp[str[i+1]]){
            n-=mp[str[i]];
        }
        else{
            n+=mp[str[i]];
        }
    }
    n+=mp[str[str.size()-1]];
    return n;
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
        cout<<romanToDecimal(s)<<endl;
              
    }
    return 0;
}
