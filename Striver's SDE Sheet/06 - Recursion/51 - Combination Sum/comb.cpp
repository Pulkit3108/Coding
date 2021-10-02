#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void subset(int id,vector<int> a,vector<int> &s,vector<vector<int>> &t,int d){
    if(d==0){
        t.push_back(s);
        return;
    }
    else if(d<0 || id==a.size()){
        return;
    } 
    if(a[id]<=d){
        s.push_back(a[id]);
        subset(id,a,s,t,d-a[id]);
        s.pop_back();
    }
    subset(id+1,a,s,t,d);
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    vector<vector<int>> t;
    vector<int> s;
    subset(0,candidates,s,t,target);
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
        int t;
        cin>>t;
        vector<vector<int>> b=combinationSum(arr,t);
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[i].size();j++){
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
