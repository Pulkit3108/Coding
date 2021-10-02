#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int compareVersion(string version1, string version2){
    for(auto &it:version1){
        if(it=='.'){
            it=' ';
        }
    }
    for(auto &it:version2){ 
        if(it=='.'){ 
            it=' ';
        }
    }
    istringstream s(version1);
    istringstream t(version2);
    while(1){
        int a,b;
        if(!(s>>a)){
            a=0;
        }
        if(!(t>>b)){ 
            b=0;
        }
        if(!s && !t){ 
            return 0;
        }
        if(a<b){ 
            return -1;
        }
        if(a>b){ 
            return 1;
        }
    }
    return 0;
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
        cout<<compareVersion(s,t)<<endl;
    }
    return 0;
}
