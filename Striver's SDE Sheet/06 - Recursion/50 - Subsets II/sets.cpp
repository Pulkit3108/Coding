#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void subset(int id,vector<int> a,vector<int> s,vector<vector<int>> &t){
    t.push_back(s);
    for(int i=id;i<a.size();i++){
        if(i==id || a[i]!=a[i-1]){
            s.push_back(a[i]);
            subset(i+1,a,s,t);
            s.pop_back();
        }
    } 
}
vector<vector<int>> subsetsWithDup(vector<int>& nums){
    vector<vector<int>> t;
    vector<int> s;
    sort(nums.begin(),nums.end());
    subset(0,nums,s,t);
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
        vector<vector<int>> b=subsetsWithDup(arr);
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[i].size();j++){
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
