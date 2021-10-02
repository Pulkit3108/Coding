#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod=1e9+7;
int maxLen(int A[], int n){
    unordered_map<int,int> mp;
    int m=0;
    int s=0;
    for(int i=0;i<n;i++){
        s+=A[i];
        if(s==0){
            m=max(m,i+1);
        }
        else if(mp.find(s)!=mp.end()){
            m=max(m,i-mp[s]);
        }
        else{
            mp[s]=i;
        }
    }
    return m;
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
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<maxLen(arr,n);
    }
    return 0;
}
