#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int matrixMultiplication(vector<int> &arr,int n){
    int dp[n-1][n-1];
    for(int g=0;g<n-1;g++){
        for(int i=0,j=g;j<n-1;i++,j++){
            if(g==0){
                dp[i][j]=0;
            }
            else if(g==1){
                dp[i][j]=arr[i]*arr[j]*arr[j+1];
            }
            else{
                dp[i][j]=INT_MAX;
                for(int k=i;k<j;k++){
                    int c=dp[i][k]+dp[k+1][j]+(arr[i]*arr[k+1]*arr[j+1]);
                    dp[i][j]=min(c,dp[i][j]);
                }
            }
        }
    }
    return dp[0][n-2];
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
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<matrixMultiplication(a,n)<<endl;
    }
    return 0;
}
