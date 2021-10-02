#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod=1e9+7;
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st;
    int r=0;
    for(int i=0;i<nums.size();i++){
        st.insert(nums[i]);
    }
    for(int i=0;i<nums.size();i++){
        if(st.find(nums[i]-1)==st.end()){
            int j=1;
            int m=1;
            while(st.find(nums[i]+j)!=st.end()){
                m+=1;
                j+=1;
            }
            r=max(r,m);
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
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<longestConsecutive(arr)<<endl;
    }
    return 0;
}
