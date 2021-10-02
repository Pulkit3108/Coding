#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string longestCommonPrefix(string arr[], int N){
    string s="";
    for(int i=0;i<arr[0].size();i++){
        for(int j=1;j<N;j++){
            if(i>arr[j].size()-1 || arr[0][i]!=arr[j][i]){
                return s.empty()?"-1":s;
            }
        }
        s+=arr[0][i];
    }  
    return s.empty()?"-1":s;
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
        string s[n];
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        cout<<longestCommonPrefix(s,n)<<endl;
    }
    return 0;
}
