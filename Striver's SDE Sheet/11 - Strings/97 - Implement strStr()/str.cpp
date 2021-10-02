#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int strStr(string haystack, string needle){
    if(needle.size()==0){
        return 0;
    }
    int h=haystack.size();
    int n=needle.size();
    int i,j;
    for(i=0;i<=h-n;i++){
        for(j=0;j<n;j++){
            if(haystack[i+j]!=needle[j]){
                break;
            }
        }
        if(j==n){
            return i;
        }
    }
    return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        string s,t;
        cin>>s>>t;
        cout<<strStr(s,t)<<endl;
              
    }
    return 0;
}
