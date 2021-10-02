#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void rotate(vector<vector<int>>& matrix) {
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<i;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }    
    for(int i=0;i<matrix.size();i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<vector<int>> a(n);
        for(int i=0;i<n;i++){
            vector<int> x(n);
            for(int j=0;j<n;j++){
                cin>>x[j];
            }
            a.push_back(x);
        }
        rotate(a);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }  
    }
    return 0;
}
