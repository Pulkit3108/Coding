#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int uniquePaths(int m, int n){
    int r=min(n-1,m-1);
    n=n+m-2;
    int i=r;
    long c1=1;
    long c2=1;
    while(i--){
        c1*=n;
        n-=1;
        c2*=r;
        r-=1;
    }
    return c1/c2;
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
        cout<<uniquePaths(n,m);
    }
    return 0;
}
