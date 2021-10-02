#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int findParent(int i,vector<int> &p){
    if(i==p[i]){
        return i;
    }
    else{
        return p[i]=findParent(p[i],p);
    }
}
void unionGraph(int i,int j,vector<int> &p,vector<int> &r){
    i=findParent(i,p);
    j=findParent(j,p);
    if(r[i]<r[j]){
        p[i]=j;
    }
    else if(r[j]<r[i]){
        p[j]=i; 
    }
    else{
        p[j]=i;
        r[i]+=1; 
    }
}
bool compare(vector<int> &a,vector<int> &b){
    return a[2]<b[2];
}
int kruskalMST(int n, int m,vector<vector<int>> &graph){
    vector<int> p(n+1);
    vector<int> r(n+1,0);
    for(int i=1;i<=n;i++){
        p[i]=i;
    }
    int c=0;
    sort(graph.begin(),graph.end(),compare);
    for (auto &it:graph){
        if(findParent(it[0],p)!=findParent(it[1],p)){
            c+=it[2];
            unionGraph(it[0],it[1],p,r);
        }
    }
    return c;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T;
    cin>>T;
    while(T--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> edges;
        for(int i=0;i<m;i++){
            int x,y,z;
            cin>>x>>y>>z;
            edges.push_back({x,y,z});
        }
        int ans=kruskalMST(n,m,edges);
        cout<<ans<<"\n";
    }
    return 0;
}
