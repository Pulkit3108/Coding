#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void insert(vector<int> &v,int t){
    if(v.size()==0 || v[v.size()-1]<t){
        v.push_back(t);
        return;
    }
    int n=v[v.size()-1];
    v.pop_back();
    insert(v,t);
    v.push_back(n);
}
void sortrecur(vector<int> &v){
    if(v.size()==0){
        return;
    }
    int n=v[v.size()-1];
    v.pop_back();
    sortrecur(v);
    insert(v,n);
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
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sortrecur(a);
        for(int i=0;i<n;i++){
            cout<<a[i];
        }
    }
    return 0;
}
