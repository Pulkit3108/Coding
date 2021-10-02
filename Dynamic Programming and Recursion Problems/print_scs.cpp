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
        string x,y;
        cin>>x>>y;
        int n=x.size();
        int m=y.size();
        int dp[n+1][m+1];
        int i,j;
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
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string s;
        i=n,j=m;
        while(i>0 && j>0){
            if(x[i-1]==y[j-1]){
                s.push_back(x[i-1]);
                i-=1;
                j-=1;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    s.push_back(x[i-1]);
                    i-=1;
                }
                else{
                    s.push_back(y[j-1]);
                    j-=1;
                }
            }
        }
        while(i>0){
            s.push_back(x[i-1]);
            i-=1;    
        }
        while(j>0){
            s.push_back(y[j-1]);
            j-=1;    
        }
        reverse(s.begin(),s.end());
        cout<<s<<endl;
    }
    return 0;
}
