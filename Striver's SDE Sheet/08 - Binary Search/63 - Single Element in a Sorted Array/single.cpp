#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int singleNonDuplicate(vector<int>& nums) {
    int l=0;
    int h=nums.size()-2;
    while(l<=h){
        int m=(l+h)/2;
        if(nums[m]==nums[m^1]){
            l=m+1;
        }
        else{
            h=m-1;
        }
    }  
    return nums[l];
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
        cout<<singleNonDuplicate(a);
    }
    return 0;
}
