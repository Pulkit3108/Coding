#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int divide(int dividend, int divisor) {
    if(dividend==INT_MIN && divisor==-1){
        return INT_MAX;
    }
    long a=abs(dividend);
    long b=abs(divisor);
    int r=0;
    while(a-b>=0){
        int x=0;
        while((a-((b<<1)<<x))>=0){
            x+=1;
        }
        r+=(1<<x);
        a-=(b<<x);
    }
    if((dividend>0)==(divisor>0)){
        return r;
    }
    else{
        return -r;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        int a,b;
        cin>>a>>b;
        
    }
    return 0;
}
