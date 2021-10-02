#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void shortest_distance(vector<vector<int>> &matrix){
    int n=matrix.size();
    for(int v=0;v<n;v++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][v]==-1 || matrix[v][j]==-1){
                    continue;
                }
                if(matrix[i][j]==-1){
                    matrix[i][j]=matrix[i][v]+matrix[v][j];
                }
                else if(matrix[i][j]>matrix[i][v]+matrix[v][j]){
                    matrix[i][j]=matrix[i][v]+matrix[v][j];
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<vector<int>>matrix(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>matrix[i][j];
            }
        }
        shortest_distance(matrix);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<"\n";
        }   
    }
    return 0;
}
