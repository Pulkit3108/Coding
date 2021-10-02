#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void dfs(vector<vector<int>>& image,int i,int j,int oc,int nc){
    if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j]!=oc){ 
        return;
    }
    image[i][j]=nc;
    dfs(image,i,j-1,oc,nc);
    dfs(image,i,j+1,oc,nc);
    dfs(image,i-1,j,oc,nc);
    dfs(image,i+1,j,oc,nc);
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
    if(image[sr][sc]!=newColor){
        dfs(image,sr,sc,image[sr][sc],newColor);
    }
    return image;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){

    }
    return 0;
}
