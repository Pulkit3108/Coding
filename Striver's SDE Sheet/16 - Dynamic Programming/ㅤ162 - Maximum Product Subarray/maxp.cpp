#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int maxProduct(vector<int>& nums){
    int dp=nums[0];
    int maxi=nums[0];
    int mini=nums[0];
    for(int i=1;i<nums.size();i++){
        int t=maxi;
        maxi=max(nums[i],max(nums[i]*maxi,nums[i]*mini));
        mini=min(nums[i],min(nums[i]*t,nums[i]*mini));
        dp=max(dp,maxi);
    }
    return dp;
}
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
        cout<<maxProduct(a)<<endl;
    }
    return 0;
}
