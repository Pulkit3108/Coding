#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool helper(int i,vector<int>adj[],vector<int> &c){
    for(auto &it:adj[i]){
        if(c[it]==-1){
            c[it]=!c[i];
            if(!helper(it,adj,c)){
                return false;
            }
        }
        else if(c[it]==c[i]){
            return false;
        }
    }
    return true;
}
bool isBipartite(int V, vector<int>adj[]){
    vector<int> c(V,-1);
    for(int i=0;i<V;i++){
        if(c[i]==-1){
            c[i]=1;
            if(!helper(i,adj,c)){
                return false;
            }
        }
    }
    return true;
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
        cout<<isBipartite(V,adj)<<endl;
    }
    return 0;
}
