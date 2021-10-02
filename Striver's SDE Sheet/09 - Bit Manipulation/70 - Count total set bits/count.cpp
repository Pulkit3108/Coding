#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int powof2(int n){
    int x=0;
    while((1<<x)<=n){
        x+=1;
    }
    return x-1;
}
int countSetBits(int n){
    if(n<=1){
        return n;
    }
    int c=0;
    int x=powof2(n);
    c=(x*(1<<(x-1)))+(n-(1<<x)+1)+countSetBits(n-(1<<x));
    return c;
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
        cout<<countSetBits(n)<<endl;
    }
    return 0;
}
