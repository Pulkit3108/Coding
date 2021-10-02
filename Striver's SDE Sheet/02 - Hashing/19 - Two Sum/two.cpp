#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod=1e9+7;
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> t;
    unordered_map<int,int> mp;
    mp[nums[0]]=0;
    for(int i=1;i<nums.size();i++){
        if(mp.find(target-nums[i])!=mp.end()){
            t.push_back(mp[target-nums[i]]);
            t.push_back(i);
            return t;
        }
        mp[nums[i]]=i;
    }
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
        vector<int> b=twoSum(arr,t);
        for(int i=0;i<b.size();i++){
            cout<<b[i]<<" ";
        }
    }
    return 0;
}
