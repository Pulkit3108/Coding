#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod=1e9+7;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> a;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            int l=j+1;
            int r=nums.size()-1;
            int s=target-nums[i]-nums[j];
            while(l<r){
                if(s>nums[l]+nums[r]){
                    l+=1;
                }
                else if(s<nums[l]+nums[r]){
                    r-=1;
                }
                else{
                    vector<int> t(4);
                    t[0]=nums[i];
                    t[1]=nums[j];
                    t[2]=nums[l];
                    t[3]=nums[r];
                    a.push_back(t);
                    while(l<r and t[2]==nums[l]){
                        l+=1;
                    }
                    while(l<r and t[3]==nums[r]){
                        r-=1;
                    }
                }
            }
            while(j+1<nums.size() and nums[j]==nums[j+1]){
                j+=1;
            }
        }
        while(i+1<nums.size() and nums[i]==nums[i+1]){
            i+=1;
        }
    }
    return a;
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
        vector<vector<int>> b=fourSum(arr,t);
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[i].size();j++){
                cout<<b[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
