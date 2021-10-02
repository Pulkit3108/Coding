#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
    vector<int> d(V,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    d[S]=0;
    pq.push({d[S],S});
    while(!pq.empty()){
        int l=pq.top().first;
        int i=pq.top().second;
        pq.pop();
        for(auto &it:adj[i]){
            int j=it[0];
            int p=it[1];
            if(d[j]>p+d[i]){
                d[j]=p+d[i];
                pq.push({d[j],j});
            }
        }
    }
    return d;
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
        int S;
        cin>>S;
        vector<int> res=dijkstra(V, adj, S);
        for(int i=0;i<V;i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;  
    }
    return 0;
}
