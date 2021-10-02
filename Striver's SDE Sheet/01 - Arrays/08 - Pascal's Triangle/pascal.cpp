#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int getpascal(int r,int c){
    int p=1;
    c=max(c,r-c);
    int m=r-1;
    while(m>c-1){
        p*=m;
        m-=1;
    }
    for(int i=1;i<r-c+1;i++){
        p/=i;
    }
    return p;
}
vector<int> pascalrow(int n){
    vector<int> p(n);
    int f=1;
    for(int i=0;i<n;i++){
        p[i]=f;
        f*=(n-i-1);
        f/=(i+1);
    }
    return p;
}
vector<vector<int>> generate(int n) {
    vector<vector<int>> p(n);
    for(int i=0;i<n;i++){
        p[i].resize(i+1);
        p[i][0]=p[i][i]=1;
        for(int j=1;j<i;j++){
            p[i][j]=p[i-1][j-1]+p[i-1][j];
        }
    }
    return p;
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
        vector<vector<int>> a=generate(n);
        vector<int> b=pascalrow(n);
        int p=getpascal(n,3);
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[i].size();j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<b.size();i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
        cout<<p;
    }
    return 0;
}
