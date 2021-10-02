#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> maximumPathBacktrack(vector<vector<int>> Matrix,int n,int m){
    int dp[n][m];
    for(int j=0;j<m;j++){
        dp[0][j]=Matrix[0][j];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(j>0 && j<m-1){
                dp[i][j]=Matrix[i][j]+max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1]));
            }
            else if(j>0){
                dp[i][j]=Matrix[i][j]+max(dp[i-1][j],dp[i-1][j-1]);
            }
            else if(j<m-1){
                dp[i][j]=Matrix[i][j]+max(dp[i-1][j],dp[i-1][j+1]);
            }
            else{
                dp[i][j]=Matrix[i][j]+dp[i-1][j];
            }
        }
    }
    int mi=INT_MIN;
    int id=0;
    for(int j=0;j<m;j++){
        if(dp[n-1][j]>mi){
            id=j;
            mi=dp[n-1][j];
        }
    }
    vector<int> p;
    p.push_back(id+1);
    int j=id;
    for(int i=n-2;i>=0;i--){
        mi=dp[i][j];
        if(j>0 && dp[i][j-1]>mi){
            mi=dp[i][j-1];
            j-=1;
        }
        if(j<m-1 && dp[i][j+1]>mi){
            mi=dp[i][j+1];
            j+=1;
        }
        p.push_back(j+1);
    }
    reverse(p.begin(),p.end());
    return p;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a;
        for(int i=0;i<n;i++){
            vector<int> t(m);
            for(int j=0;j<m;j++){
                cin>>t[j];
            }
            a.push_back(t);
        }
        vector<int> b=maximumPathBacktrack(a,n,m);
        for(int i=0;i<b.size();i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
