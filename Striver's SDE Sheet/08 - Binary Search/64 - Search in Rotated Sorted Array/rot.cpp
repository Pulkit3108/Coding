#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int search(vector<int>& nums, int target){
    int l=0;
    int h=nums.size()-1;
    while(l<=h){
        int m=(l+h)/2;
        if(nums[m]==target){
            return m;
        }
        if(nums[l]<=nums[m]){
            if(target>=nums[l] && target<nums[m]){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        else{
            if(target>nums[m] && target<=nums[h]){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
    }
    return -1;
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
        int t;
        cin>>t;
        cout<<search(a,t)<<endl;
    }
    return 0;
}
