#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int lcs(string x,string y,int n,int m){
    if(n==0 || m==0){
        return 0;
    }
    if(x[n-1]==y[m-1]){
        return(1+lcs(x,y,n-1,m-1));
    }
    else{
        return(max(lcs(x,y,n,m-1),lcs(x,y,n-1,m)));
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,m;
        string x,y;
        cin>>n>>m;
        cin>>x>>y;
        int c=lcs(x,y,n,m);
        cout<<c<<endl;
    }
    return 0;
}
