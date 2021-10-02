#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void helper(int i,vector<int> &v,vector<int> adj[],stack<int> &st){
    v[i]=1;
    for(auto &it:adj[i]){
        if(!v[it]){
            helper(it,v,adj,st);
        }
    }
    st.push(i);
}
void dfs(int i,vector<int> &v,vector<int> adj[]){
    v[i]=1;
    for(auto &it:adj[i]){
        if(!v[it]){
            dfs(it,v,adj);
        }
    }
}
int kosaraju(int V, vector<int> adj[]){
    vector<int> v(V,0);
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!v[i]){
            helper(i,v,adj,st);
        }
    }
    vector<int> t[V];
    for(int i=0;i<V;i++){
        v[i]=0;
        for(auto &it:adj[i]){
            t[it].push_back(i);
        }
    }
    int c=0;
    while(!st.empty()){
        int i=st.top();
        st.pop();
        if(!v[i]){
            dfs(i,v,t);
            c+=1;
        }
    }
    return c;
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
        cout<<kosaraju(V,adj)<<endl;
    }
    return 0;
}
