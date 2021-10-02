#include<bits/stdc++.h>
using namespace std;
#define ll long long int
static bool safe(bool graph[101][101],int v,int c[],int nd,int cl){
    for(int i=0;i<v;i++){
        if(i!=nd && graph[i][nd]==1 && c[i]==cl){
            return false;
        }
    }
    return true;
}
static bool recur(bool graph[101][101],int m,int v,int c[],int nd){
   if(nd==v){
       return true;
   } 
   for(int i=1;i<=m;i++){
       if(safe(graph,v,c,nd,i)){
           c[nd]=i;
           if(recur(graph,m,v,c,nd+1)){
               return true;
           }
           c[nd]=0;
       }
   }
   return false;
}
bool graphColoring(bool graph[101][101], int m, int V){
    int c[V]={0};
    if(recur(graph,m,V,c,0)){
        return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        int n,m,e;
        cin>>n>>m>>e;
        int i;
        bool graph[101][101];
        for(i=e;i<n;i++){
            memset(graph[i], 9, sizeof(graph[i]));
        }
        for(i=e;i<e;i++){
            int a,b;
            cin>>a>>b;
            graph[a-1][b-1]=1;
            graph[b-1][a-1]=1;
        }
        cout<<graphColoring(graph,m,n)<<endl; 
    }
    return 0;
}
