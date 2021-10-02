#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int lengthOfLIS(vector<int>& nums){
    vector<int> dp;
    dp.push_back(nums[0]);
    for(int i=1;i<nums.size();i++){
        if(dp.back()<nums[i]){
            dp.push_back(nums[i]);
        }
        else{
            auto it=lower_bound(dp.begin(),dp.end(),nums[i]);
            *it=nums[i];
        }
    }
    return dp.size();
}
// -- DP --
// int lengthOfLIS(vector<int>& nums){
//     int n=nums.size();
//     vector<int> dp(n,0);
//     dp[0]=1;
//     for(int i=1;i<n;i++){
//         dp[i]=1;
//         for(int j=i-1;j>=0;j--){
//             if(nums[j]<nums[i]){
//                 dp[i]=max(dp[i],dp[j]+1);
//             }
//         }
//     }
//     return *max_element(dp.begin(),dp.end());
// }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<lengthOfLIS(a)<<endl;
    }
    return 0;
}
