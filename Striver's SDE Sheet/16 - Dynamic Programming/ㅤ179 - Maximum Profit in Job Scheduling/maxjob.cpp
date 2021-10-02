#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
    int n=profit.size();
    vector<vector<int>> jb;
    for(int i=0;i<n;i++){
        vector<int> t;
        t.push_back(endTime[i]);
        t.push_back(startTime[i]);
        t.push_back(profit[i]);
        jb.push_back(t);
    }
    sort(jb.begin(),jb.end());
    int dp[n];
    dp[0]=jb[0][2];
    for(int i=1;i<n;i++){
        int c=jb[i][2];
        int id=-1;
        for(int j=i-1;j>=0;j--){
            if(jb[j][0]<=jb[i][1]){
                id=j;
                break;
            }
        }
        if(id!=-1){
            c+=dp[id];
        }
        dp[i]=max(c,dp[i-1]);
    }
    return dp[n-1];
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
        vector<int> b(n);
        vector<int> c(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        cout<<jobScheduling(a,b,c)<<endl;
    }
    return 0;
}
