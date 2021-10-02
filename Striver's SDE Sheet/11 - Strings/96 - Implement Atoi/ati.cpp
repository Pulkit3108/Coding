#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int atoi(string str){
    int s=1;
    int i=0;
    int n=0;
    if(str[0]=='-'){
        i=1;
        s=-1;
    }
    for(;i<str.size();i++){
        if(str[i]>='0' && str[i]<='9'){
            n=n*10+(str[i]-'0');
        }
        else{
            return -1;
        }
    }
    return n*s;
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
        cout<<atoi(s)<<endl;
              
    }
    return 0;
}
