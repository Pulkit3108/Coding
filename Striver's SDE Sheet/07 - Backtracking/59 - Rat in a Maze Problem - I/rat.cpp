#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void recur(int i,int j,vector<string> &t,vector<vector<int>> &m,int n,string s,vector<vector<int>> &v,int d1[],int d2[]){
    if(i==n-1 && j==n-1){
        t.push_back(s);
        return;
    }
    string d="DLRU";
    for(int c=0;c<4;c++){
        int a=i+d1[c];
        int b=j+d2[c];
        if(a>=0 && b>=0 && a<n && b<n){
            if(!v[a][b] && m[a][b]==1){
                v[a][b]=1;
                s.push_back(d[c]);
                recur(a,b,t,m,n,s,v,d1,d2);
                s.pop_back();
                v[a][b]=0;
            }
        }   
    }
}
vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> t;
    string s="";
    vector<vector<int>> v(n,vector<int> (n,0));
    int d1[4]={1,0,0,-1};
    int d2[4]={0,-1,1,0};
    v[0][0]=1;
    if(m[0][0]==1){
        recur(0,0,t,m,n,s,v,d1,d2);
    }
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
        vector<vector<int>> b;
        for(int i=0;i<n;i++){
            vector<int> c(n);
            for(int j=0;j<n;j++){
                int ch;
                cin>>ch;
                c[j]=ch;
            }
            b.push_back(c);
        }
        vector<string> s=findPath(b,n);
        for(int i=0;i<s.size();i++){
            cout<<s[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
