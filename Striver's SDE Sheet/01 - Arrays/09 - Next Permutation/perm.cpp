#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void nextPermutation(vector<int>& nums) {
    int j=-1;
    for(int i=nums.size()-2;i>=0;i--){
        if(nums[i]<nums[i+1]){
            j=i;
            break;
        }
    }
    if(j!=-1){
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>nums[j]){
                swap(nums[i],nums[j]);
                break;
            }
        }
    }
    reverse(nums.begin()+j+1,nums.end());
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
        nextPermutation(a);
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
    }
    return 0;
}
