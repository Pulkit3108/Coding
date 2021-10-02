#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int removeDuplicates(vector<int>& nums) {
    if(nums.size()==0){
        return 0;
    }
    int i=0;
    int d=1;
    for(int j=1;j<nums.size();j++){
        if(nums[i]!=nums[j]){
            i+=1;
            swap(nums[i],nums[j]);
            d+=1;
        }
    }
    return d;
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
        cout<<removeDuplicates(arr)<<endl;
    }
    return 0;
}
