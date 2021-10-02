#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int josephus(int i,int k,vector<int> &j){
    if(j.size()==1){
        return j.front();
    }
    i=(i+k)%j.size();
    j.erase(j.begin()+i);
    return josephus(i,k,j);
}
int safePos(int n, int k){
    vector<int> j(n);
    for(int i=0;i<n;i++){
        j[i]=i+1;
    }
    return josephus(0,k-1,j);
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
        cout<<safePos(n,k)<<endl;
        
    }
    return 0;
}
