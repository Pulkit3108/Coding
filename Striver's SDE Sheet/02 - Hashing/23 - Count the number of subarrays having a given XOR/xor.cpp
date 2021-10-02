#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod=1e9+7;
long long subarrayXor(int arr[], int n, int m){
    unordered_map<int,int> mp;
    int x=0;
    int c=0;
    for(int i=0;i<n;i++){
        x=x^arr[i];
        if(x==m){
            c+=1;
        }
        if(mp.find(x^m)!=mp.end()){
            c+=mp[x^m];
        }
        mp[x]+=1;
    }
    return c;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<subarrayXor(arr,n,m);
    }
    return 0;
}
