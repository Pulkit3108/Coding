#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,i,j,s=0;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++){
            cin>>a[i];
            s+=a[i];
        }
        int dp[n+1][s+1];
        for(i=0;i<n+1;i++){
            for(j=0;j<s+1;j++){
                if(i==0){
                    dp[i][j]=false;
                }
                if(j==0){
                    dp[i][j]=true;
                }
            }
        }
        for(i=1;i<n+1;i++){
            for(j=1;j<s+1;j++){
                if(a[i-1]<=j){
                    dp[i][j]=dp[i-1][j-a[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        for(j=s/2;j>=0;j--){
            if(dp[n][j]){
                break;
            }
        }
        cout<<(s-2*j)<<endl;
        // vector<int> k;
        // for(j=0;j<s/2+1;j++){
        //     if(dp[n][j]){
        //         k.push_back(j);
        //     }
        // }
        // int mn=INT16_MAX;
        // for(i=0;i<k.size();i++){
        //     mn=min(mn,s-2*k[i]);
        // }
        // cout<<mn<<endl;
    }
    return 0;
}
