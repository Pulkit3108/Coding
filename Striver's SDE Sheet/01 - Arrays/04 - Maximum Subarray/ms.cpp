#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int maxSubArray(vector<int>& nums){
    int m=nums[0];
    int s=0;
    for(int i=0;i<nums.size();i++){
        s+=nums[i];
        m=max(m,s);
        s=max(s,0);
    }
    return m;
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
        cout<<maxSubArray(arr);
    }
    return 0;
}
