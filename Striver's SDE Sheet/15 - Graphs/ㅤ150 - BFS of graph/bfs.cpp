#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> bfsOfGraph(int V, vector<int> adj[]){
    vector<int> v(V+1,0);
    vector<int> bfs;
    queue<int> q;
    q.push(0);
    v[0]=1;
    while(!q.empty()){
        int i=q.front();
        q.pop();
        bfs.push_back(i);
        for(auto &it:adj[i]){
            if(!v[it]){
                v[it]=1;
                q.push(it);
            }
        }
    }
    return bfs;
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
        vector<int>ans=bfsOfGraph(V,adj);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
