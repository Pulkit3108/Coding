#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void recur(int id,vector<vector<int>> &t,vector<int> &nums){
    if(id==nums.size()){
        t.push_back(nums);
        return;
    }
    for(int i=id;i<nums.size();i++){
        swap(nums[id],nums[i]);
        recur(id+1,t,nums);
        swap(nums[id],nums[i]);
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> t;
    recur(0,t,nums);
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
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<vector<int>> b=permute(a);
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[i].size();j++){
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
