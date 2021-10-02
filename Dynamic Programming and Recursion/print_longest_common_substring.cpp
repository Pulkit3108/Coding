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
        int n,m,i,j,s=0,k;
        string x,y;
        cin>>n>>m;
        cin>>x>>y;
        int dp[n+1][m+1];
        for(i=0;i<n+1;i++){
            for(j=0;j<m+1;j++){
                if(i==0 || j==0){
                    dp[i][j]=0;
                }
            }
        }
        for(i=1;i<n+1;i++){
            for(j=1;j<m+1;j++){
                if(x[i-1]==y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=0;
                }
                if(s<=dp[i][j]){
                    s=dp[i][j];
                    k=i;
                }
            }
        }
        string c;
        while(s!=0){
            c.push_back(x[k-1]);
            s-=1;
            k-=1;
        }
        reverse(c.begin(),c.end());
        cout<<c<<endl;
    }
    return 0;
}
