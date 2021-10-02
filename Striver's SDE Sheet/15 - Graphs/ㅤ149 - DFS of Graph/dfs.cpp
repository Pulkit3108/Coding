#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void helper(int i,vector<int> &v,vector<int> adj[],vector<int> &dfs){
    v[i]=1;
    dfs.push_back(i);
    for(auto &it:adj[i]){
        if(!v[it]){
            helper(it,v,adj,dfs);
        }
    }
}
vector<int> dfsOfGraph(int V,vector<int> adj[]){
    vector<int> v(V,0);
    vector<int> dfs;
    for(int i=0;i<V;i++){
        if(!v[i]){
            helper(i,v,adj,dfs);
        }
    }
    return dfs;;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        int V,E;
        cin>>V>>E;
        vector<int> adj[V];
        for(int i=0;i<E;i++){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>ans=dfsOfGraph(V,adj);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
