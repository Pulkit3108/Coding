#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void setZeroes(vector<vector<int>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    bool c=true;
    for(int i=0;i<n;i++){
        if(matrix[i][0]==0){
            c=false;
        }
        for(int j=1;j<m;j++){
            if(matrix[i][j]==0){
                matrix[i][0]=matrix[0][j]=0;
            }
        }
    }   
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=1;j--){
            if(matrix[i][0]==0 or matrix[0][j]==0){
                matrix[i][j]=0;
            }
        }
        if(!c){
            matrix[i][0]=0;
        }
    } 
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
            vector<int> x(m);
            for(int j=0;j<m;j++){
                cin>>x[j];
            }
            a.push_back(x);
        }
        setZeroes(a);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
