#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int orangesRotting(vector<vector<int>>& grid){
    if(grid.empty()){
        return 0;
    }
    int n=grid.size();
    int m=grid[0].size();
    int o=0;
    int t=0;
    int c=0;
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]!=0){
                o+=1;
            }
            if(grid[i][j]==2){
                q.push({i,j});
            }
        }
    } 
    while(!q.empty()){
        int s=q.size();
        c+=s;
        while(s--){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            int dx[4]={0,0,1,-1};
            int dy[4]={1,-1,0,0}; 
            for(int d=0;d<4;d++){
                int x=i+dx[d];
                int y=j+dy[d];
                if(x<0 || y<0 || x>n-1 || y>m-1 || grid[x][y]!=1){
                    continue;
                }
                else{
                    grid[x][y]=2;
                    q.push({x,y});
                }
            }
        }
        if(!q.empty()){
            t+=1;
        }
    }
    return c==o?t:-1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a;
        for(int i=0;i<n;i++){
            vector<int> b(m);
            for(int j=0;j<m;j++){
                cin>>b[j];
            }
            a.push_back(b);
        }
        cout<<orangesRotting(a)<<endl;
    }
    return 0;
}
