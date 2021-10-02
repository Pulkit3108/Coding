#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void helper(int i,vector<int> adj[],vector<int> &v,stack<int> &st){
    v[i]=1;
    for(auto &it:adj[i]){
        if(!v[it]){
            helper(it,adj,v,st);
        }
    }
    st.push(i);
}
vector<int> topoSort(int V, vector<int> adj[]){
    vector<int> v(V,0);
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!v[i]){
            helper(i,adj,v,st);
        }
    }
    vector<int> t;
    while(!st.empty()){
        t.push_back(st.top());
        st.pop();
    }
    return t;
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
        vector<int> ans=topoSort(V,adj);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
