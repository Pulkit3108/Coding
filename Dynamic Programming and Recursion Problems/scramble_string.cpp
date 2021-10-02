#include<bits/stdc++.h>
using namespace std;
#define ll long long int
unordered_map<string, bool> mp;
bool scramble(string a,string b){
    if(a.compare(b)==0){
        return true;
    }
    if(a.length()<=1){
        return false;
    }
    string t=a;
    t.push_back(' ');
    t.append(b);
    if(mp.find(t)!=mp.end()){
        return(mp[t]);
    }
    int k;
    bool f=false;
    int n=a.size();
    for(k=1;k<n;k++){
        bool t1,t2,t3,t4;
        t1=scramble(a.substr(0,k),b.substr(n-k,k));
        t2=scramble(a.substr(k,n-k),b.substr(0,n-k));
        t3=scramble(a.substr(0,k),b.substr(0,k));
        t4=scramble(a.substr(k,n-k),b.substr(k,n-k));
        if((t1 && t2) || (t3 && t4)){
            f=true;
            break;
        }
    }
    mp[t]=f;
    return(f);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        string a,b;
        cin>>a>>b;
        if(a.length()!=b.length()){
            cout<<"False"<<endl;
        }
        else{
            mp.clear();
            if(scramble(a,b)){
                cout<<"True"<<endl;
            }
            else{
                cout<<"False"<<endl;
            }
        }
    }
    return 0;
}
