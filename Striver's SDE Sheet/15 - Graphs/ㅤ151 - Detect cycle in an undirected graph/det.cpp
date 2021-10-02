#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool helper(int i,int p,vector<int> adj[],vector<int> &v){
    v[i]=1;
    for(auto it:adj[i]){
        if(!v[it]){
            if(helper(it,i,adj,v)){
                return true;
            }
        }
        else if(it!=p){
            return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[]){
    vector<int> v(V,0);
    for(int i=0;i<V;i++){
        if(!v[i]){
            if(helper(i,-1,adj,v)){
                return true;
            }
        }
    }
    return false;
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
        cout<<isCycle(V,adj)<<endl;
    }
    return 0;
}
