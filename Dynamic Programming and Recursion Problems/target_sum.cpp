#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int count_subset_sum(int a[],int n, int s){
    int i,j,c=0;
    int dp[n+1][s+1];
    for(i=0;i<n;i++){
        if(a[i]==0){
            c+=1;
        }
    }
    for(i=0;i<n+1;i++){
        for(j=0;j<s+1;j++){
            if(i==0){
                dp[i][j]=0;
            }
            if(j==0){
                dp[i][j]=1;
            }
        }
    }
    for(i=1;i<n+1;i++){
        for(j=1;j<s+1;j++){
            if(a[i-1]==0){
                dp[i][j]=dp[i-1][j];
            }
            else if(a[i-1]<=j){
                dp[i][j]=dp[i-1][j-a[i-1]]+dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return(pow(2,c)*dp[n][s]);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,i,j,s=0,d;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++){
            cin>>a[i];
            s+=a[i];
        }
        cin>>d;
        if((s+d)%2!=0 or d>s){
            cout<<0<<endl;
        }
        else{
            int x=(s+d)/2;
            cout<<count_subset_sum(a,n,x)<<endl;
        }
    }
    return 0;
}
