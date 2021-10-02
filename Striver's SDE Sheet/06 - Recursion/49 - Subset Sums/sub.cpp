#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void subset(vector<int> arr,int s,vector<int> &t){
    if(arr.size()==0){
        t.push_back(s);
        return;
    }
    int n=s;
    s+=arr.front();
    arr.erase(arr.begin());
    subset(arr,n,t);
    subset(arr,s,t);
    
}
vector<int> subsetSums(vector<int> arr,int N){
    vector<int> t;
    int s=0;
    subset(arr,s,t);
    return t;
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
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> b=subsetSums(arr,n);
        for(int i=0;i<b.size();i++){
            cout<<b[i]<<" ";
        }
    }
    return 0;
}
