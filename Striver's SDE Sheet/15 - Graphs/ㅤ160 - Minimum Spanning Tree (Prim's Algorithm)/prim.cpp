#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int spanningTree(int V, vector<vector<int>> adj[]){
    vector<int> d(V,INT_MAX);
    vector<int> v(V,0);
    vector<int> p(V,-1);
    d[0]=0;
    v[0]=1;
    priority_queue<pair<int,int>,vector <pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({d[0],0});
    while(!pq.empty()){
        int i=pq.top().second;
        pq.pop();
        v[i]=1;
        for(auto &it:adj[i]){
            int j=it[0];
            int w=it[1];
            if(!v[j] && w<d[j]){
                p[j]=i;
                d[j]=w;
                pq.push({d[j],j});
            }
        }
    }
    return accumulate(d.begin(),d.end(),0);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        int V, E;
        cin>>V>>E;
        vector<vector<int>> adj[V];
        int i=0;
        while(i++<E){
            int u,v,w;
            cin>>u>>v>>w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        cout<<spanningTree(V,adj)<<endl;
    }
    return 0;
}
