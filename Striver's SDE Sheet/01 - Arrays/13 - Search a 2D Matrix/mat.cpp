#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int matSearch (int N, int M, int matrix[][M], int x){
    int i=0;
    int j=M-1;
    while(i<N && j>-1){
        if(matrix[i][j]==x){
            return 1;
        }
        else if(matrix[i][j]<x){
            i+=1;
        }
        else{
            j-=1;
        }
    }
    return 0;
}
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n=matrix.size();
    int m=matrix[0].size();
    int l=0;
    int h=n*m-1;
    int mid;
    while(l<=h){
        mid=(l+h)/2;
        int i=mid/m;
        int j=mid%m;
        if(matrix[i][j]==target){
            return true;
        }
        else if(matrix[i][j]<target){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
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
        int t;
        cin>>t;
        cout<<searchMatrix(a,t); 
    }
    return 0;
}
