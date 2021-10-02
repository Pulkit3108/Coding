#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool isSubsetSum(int N, int arr[], int sum){
    bool dp[N+1][sum+1];
    for(int j=0;j<sum+1;j++){
        dp[0][j]=false;
    }
    for(int i=0;i<N+1;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<N+1;i++){
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[N][sum];
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
        int v;
        cin>>v;
        cout<<isSubsetSum(n,a,v)<<endl;
    }
    return 0;
}
