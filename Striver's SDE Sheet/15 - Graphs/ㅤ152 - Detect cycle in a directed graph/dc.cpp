#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool helper(int i,vector<int> adj[],vector<int> &v,vector<int> &dv){
    v[i]=1;
    dv[i]=1;
    for(auto &it:adj[i]){
        if(!v[it]){
            if(helper(it,adj,v,dv)){
                return true;
            }
        }
        else if(dv[it]){
            return true;
        }
    }
    dv[i]=0;
    return false;
}
bool isCyclic(int V, vector<int> adj[]){
    vector<int> v(V,0);
    vector<int> dv(V,0);
    for(int i=0;i<V;i++){
        if(!v[i]){
            if(helper(i,adj,v,dv)){
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
        cout<<isCyclic(V,adj)<<endl;
    }
    return 0;
}
