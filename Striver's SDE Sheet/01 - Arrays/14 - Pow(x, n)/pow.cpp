#include<bits/stdc++.h>
using namespace std;
#define ll long long int
double myPow(double x, int n) {
    double a=1;
    long int p=n;
    if(n<0){
        p=-1LL*n;
    }
    while(p){
        if(p&1){
            a*=x;
            p-=1;
        }
        else{
            x*=x;
            p=p>>1;
        }
    }
    if(n<0){
        a=(double)1/a;
    }
    return a;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        double x;
        int n;
        cin>>x>>n;
        cout<<myPow(x,n); 
    }
    return 0;
}
