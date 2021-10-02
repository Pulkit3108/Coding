
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> r;
    if(nums.size()<3){
        return r;
    }
    for(int i=0;i<nums.size()-2;i++){
        if(i==0 || (i>0 && nums[i-1]!=nums[i])){
            int l=i+1;
            int h=nums.size()-1;
            int s=-nums[i];
            while(l<h){
                if(nums[l]+nums[h]==s){
                    vector<int> t;
                    t.push_back(nums[i]);
                    t.push_back(nums[l]);
                    t.push_back(nums[h]);
                    r.push_back(t);
                    l+=1;
                    h-=1;
                    while(l<h && nums[l]==nums[l-1]){
                        l+=1;
                    }
                    while(l<h && nums[h]==nums[h+1]){
                        h-=1;
                    }
                }
                else if(nums[l]+nums[h]>s){
                    h-=1;
                }
                else{
                    l+=1;
                }
            }
        }
    }
    return r;
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
        vector<vector<int>> m=threeSum(a);
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[i].size();j++){
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
