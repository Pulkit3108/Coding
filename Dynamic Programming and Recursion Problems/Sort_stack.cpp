#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void insert(stack<int> &s,int t){
    if(s.size()==0 || s.top()<t){
        s.push(t);
        return;
    }
    int n=s.top();
    s.pop();
    insert(s,t);
    s.push(n);
}
void sortrecur(stack<int> &s){
    if(s.size()==0){
        return;
    }
    int n=s.top();
    s.pop();
    sortrecur(s);
    insert(s,n);
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
        sortrecur(s);
        for(int i=0;i<n;i++){
            cout<<s.top();
            s.pop();
        }
    }
    return 0;
}
