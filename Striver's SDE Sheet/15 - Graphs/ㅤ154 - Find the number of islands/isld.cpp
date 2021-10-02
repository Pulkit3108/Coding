#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int helper(int i,int j,vector<vector<char>>  &grid){
    if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j]=='0'){
        return 0;
    }
    grid[i][j]='0';
    helper(i+1,j,grid);
    helper(i+1,j+1,grid);
    helper(i+1,j-1,grid);
    helper(i-1,j,grid);
    helper(i-1,j+1,grid);
    helper(i-1,j-1,grid);
    helper(i,j+1,grid);
    helper(i,j-1,grid);
    return 1;
}
int numIslands(vector<vector<char>> &grid){
    int n=grid.size();
    int m=grid[0].size();
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1'){
                c+=helper(i,j,grid);
            }
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
        int n,m;
        cin>>n>>m;
        vector<vector<char>> a;
        for(int i=0;i<n;i++){
            vector<char> ch(m); 
            for(int j=0;j<m;j++){
                cin>>ch[j];
            }
            a.push_back(ch);
        }
        cout<<numIslands(a)<<endl;
    }
    return 0;
}
