#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int square(int n){
    if(n==0){
        return 0;
    }
    if(n<0){
        n=-n;
    }
    int x=n>>1;
    if(n&1){
        return((square(x)<<2)+(x<<2)+1);
    }
    else{
        return(square(x)<<2);
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
        cout<<square(n)<<endl;
    }
    return 0;
}
