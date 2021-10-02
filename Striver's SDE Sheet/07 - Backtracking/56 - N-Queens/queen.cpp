#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void recur(int c,vector<string> &b,vector<vector<string>> &t, vector<int> &lr, vector<int> &ld, vector<int> &ud, int n){
    if(c==n){
        t.push_back(b);
        return;
    }
    for(int i=0;i<n;i++){
        if(lr[i]==0 && ld[i+c]==0 && ud[(n-1)+(c-i)]==0){
            b[i][c]='Q';
            lr[i]=1;
            ld[i+c]=1;
            ud[(n-1)+(c-i)]=1;
            recur(c+1,b,t,lr,ld,ud,n);
            b[i][c]='.';
            lr[i]=0;
            ld[i+c]=0;
            ud[(n-1)+(c-i)]=0;
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> t;
    vector<string> b(n);
    string s(n,'.');
    for(int i=0;i<n;i++){
        b[i]=s; 
    } 
    vector<int> lr(n,0), ld(2*n-1,0), ud(2*n-1,0); 
    recur(0,b,t,lr,ld,ud,n); 
    return t; 
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
        vector<vector<string>> b=solveNQueens(n);
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[i].size();j++){
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
