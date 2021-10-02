#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void midpop(stack<int> &s,int k){
    if(k==1){
        s.pop();
        return;
    }
    int t=s.top();
    s.pop();
    midpop(s,k-1);
    s.push(t);
    return;
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
        stack<int> s;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            s.push(x);
        }
        midpop(s,n/2+1);
        for(int i=0;i<n-1;i++){
            cout<<s.top();
            s.pop();
        }
    }
    return 0;
}
