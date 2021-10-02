#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int setBitNumber(int n){
    n=n|(n>>1);
    n=n|(n>>2);
    n=n|(n>>4);
    n=n|(n>>8);
    n=n|(n>>16);
    n=n+1;
    return (n>>1);
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
        cout<<setBitNumber(n)<<endl;
    }
    return 0;
}
