#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int maxSumIS(int arr[], int n)  {  
    vector<int> dp(arr,arr+n);
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]){
                dp[i]=max(dp[i],arr[i]+dp[j]);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
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
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<maxSumIS(a,n)<<endl;
    }
    return 0;
}
