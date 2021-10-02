#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int isNegativeWeightCycle(int n, vector<vector<int>>edges){
    vector<int> d(n,INT_MAX);
    d[0]=0;
    for(int i=0;i<n-1;i++){
        for(auto &it:edges){
            if(d[it[0]]!=INT_MAX && (d[it[0]]+it[2]<d[it[1]])){
                d[it[1]]=d[it[0]]+it[2];
            }
        }
    }
    for(auto &it:edges){
        if(d[it[0]]!=INT_MAX && (d[it[0]]+it[2]<d[it[1]])){
            return 1;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> edges;
        for(int i=0;i<m;i++){
            int x,y,z;
            cin>>x>>y>>z;
            edges.push_back({x,y,z});
        }
        int ans=isNegativeWeightCycle(n,edges);
        cout<<ans<<"\n";    
    }
    return 0;
}
