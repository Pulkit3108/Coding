#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> dNums(vector<int>& nums, int k){
    vector<int> d;
    unordered_map<int,int> mp;
    for(int i=0;i<k-1;i++){
        mp[nums[i]]+=1;
    }
    for(int i=k-1,j=0;i<nums.size();i++,j++){
        mp[nums[i]]+=1;
        d.push_back(mp.size());
        if(mp[nums[j]]==1){
            mp.erase(nums[j]);
        }
        else{
            mp[nums[j]]-=1;
        }
    }
    return d;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){

    }
    return 0;
}
