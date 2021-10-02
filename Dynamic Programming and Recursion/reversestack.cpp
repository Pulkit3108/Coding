#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void insertbottom(stack<int> &s,int t){
    if(s.size()==0){
        s.push(t);
        return;
    }
    int b=s.top();
    s.pop();
    insertbottom(s,t);
    s.push(b);
}
void reversestack(stack<int> &s){
    if(s.size()==1){
        return;
    }
    int t=s.top();
    s.pop();
    reversestack(s);
    insertbottom(s,t);
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
        reversestack(s);
        for(int i=0;i<n;i++){
            cout<<s.top();
            s.pop();
        }
    }
    return 0;
}
