#include<bits/stdc++.h>
using namespace std;
#define ll long long int
double mul(int a,int n){
    double f=1.0;
    for(int i=1;i<n+1;i++){
        f*=a;
    }
    return f;
}
double nthroot(int a,int n){
    double l=1;
    double h=a;
    double eps=1e-6;
    while(h-l>eps){
        double m=(h+l)/2.0;
        if(mul(m,n)<a){
            l=m;
        }
        else{
            h=m;
        }
    }
    return h;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        int a,n;
        cin>>a>>n;
        cout<<nthroot(a,n)<<endl;
        
    }
    return 0;
}
