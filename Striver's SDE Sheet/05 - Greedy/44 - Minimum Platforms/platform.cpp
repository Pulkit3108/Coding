#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int findPlatform(int arr[], int dep[], int n){
    sort(arr,arr+n);
    sort(dep,dep+n);
    int pm=1;
    int pc=1;
    int d=0;
    int a=1;
    while(a<n && d<n){
        if(arr[a]<=dep[d]){
            pc+=1;
            a+=1;
        }
        else{
            pc-=1;
            d+=1;
        }
        pm=max(pm,pc);
    }
    return pm;
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
        int arr1[n],arr2[n];
        for(int i=0;i<n;i++){
            cin>>arr1[i];
        }
        for(int i=0;i<n;i++){
            cin>>arr2[i];
        }
        cout<<findPlatform(arr1,arr2,n)<<endl;
    }
    return 0;
}
