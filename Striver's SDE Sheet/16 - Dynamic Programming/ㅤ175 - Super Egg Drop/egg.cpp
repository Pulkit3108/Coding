#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int superEggDrop(int k, int n){
    int dp[k+1][n+1];
    for(int i=0;i<k+1;i++){
        dp[i][0]=0;
        dp[i][1]=1;
    }
    for(int j=0;j<n+1;j++){
        dp[0][j]=0;
        dp[1][j]=j;
    }
    for(int i=2;i<k+1;i++){
        for(int j=2;j<n+1;j++){
            // int m=INT_MAX;
            // for(int k=j-1,l=0;k>=0;k--,l++){
            //     m=min(m,max(dp[i][k],dp[i-1][l]));
            // }
            // dp[i][j]=1+m;
            int lo=1;
            int hi=j;
            int t=0;
            int mi=INT_MAX;
            while(lo<=hi){
                int m=(lo+hi)/2;
                int l=dp[i-1][m-1];
                int r=dp[i][j-m];
                t=1+max(l,r);  
                if(l<r){                  
                    lo=m+1;                       
                }
                else{    
                    hi=m-1;
                }
                mi=min(mi,t);              
            }
            dp[i][j]=mi;
        }
    }
    return dp[k][n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        int k,n;
        cin>>k>>n;
        cout<<superEggDrop(k,n)<<endl;
        
    }
    return 0;
}
