#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
const int N=1e3+10;
const int inf=1e9+10;
int dist[N][N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==j){
                    dist[i][j]=0;
                }
                else{
                    dist[i][j]=inf;
                }
            }
        }
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int x,y,wt;
            cin>>x>>y>>wt;
            dist[x][y]=wt;
        }
        for(int k=1;k<n;k++){
            for(int i=1;i<n+1;i++){
                for(int j=1;j<n+1;j++){
                    if(dist[i][k]!=inf && dist[k][j]!=inf){
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(dist[i][j]==inf){
                    cout<<"I"<<" ";
                }
                else{
                    cout<<dist[i][j]<<" ";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}

