#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool subset_sum(int a[], int s, int n){
    int i,j;
    bool dp[n+1][s+1];
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
    return(dp[n][s]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,s=0,i;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++){
            cin>>a[i];
            s+=a[i];
        }
        if(s%2!=0 || !subset_sum(a,s/2,n)){
            cout<<"False"<<endl;
        }
        else{
            cout<<"True"<<endl;
        }
    }
    return 0;
}
