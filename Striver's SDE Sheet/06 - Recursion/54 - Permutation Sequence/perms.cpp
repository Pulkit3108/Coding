#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string getPermutation(int n, int k){
    int f=1;
    vector<int> d;
    for(int i=1;i<n;i++){
        f=f*i;
        d.push_back(i);
    }     
    d.push_back(n);
    string s="";
    k-=1;
    while(true){
        s=s+to_string(d[k/f]);
        d.erase(d.begin() + k/f);
        if(d.size()==0){
            break;
        }
        k=k%f;
        f=f/d.size();
    }
    return s;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        cout<<getPermutation(n,k)<<endl;
    }
    return 0;
}
