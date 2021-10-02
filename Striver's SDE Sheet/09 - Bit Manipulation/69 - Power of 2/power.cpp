#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool isPowerofTwo(long long n){
    if(n==0 || (n&(n-1))!=0){
        return false;;
    }
    else{
        return true;
    }        
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        ll n;
        cin>>n;
        if(isPowerofTwo(n)){
            cout<<"False";
        }
        else{
            cout<<"True";
        }
        cout<<endl;
    }
    return 0;
}
