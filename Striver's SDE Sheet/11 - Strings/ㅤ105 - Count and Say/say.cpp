#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string countAndSay(int n){
    if(n==1){
        return "1";
    }
    string s=countAndSay(n-1);
    string t;
    while(1){
        char ch=s[0];
        int c=0;
        while(s[c]==ch){
            c+=1;
        }    
        t+=to_string(c)+ch;   
        s.erase(0,c);
        if(s.size()==0){
            break;
        }
    } 
    return t;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        cout<<countAndSay(n)<<endl;
    }
    return 0;
}
