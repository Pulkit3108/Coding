#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void sortColors(vector<int>& nums){
    int l=0;
    int m=0;
    int h=nums.size()-1;
    while(m<=h){
        if(nums[m]==0){
            swap(nums[l],nums[m]);
            l+=1;
            m+=1;
        }
        else if(nums[m]==1){
            m+=1;
        }
        else{
            swap(nums[h],nums[m]);
            h-=1;
        }
    }
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
        sortColors(arr);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        
    }
    return 0;
}
