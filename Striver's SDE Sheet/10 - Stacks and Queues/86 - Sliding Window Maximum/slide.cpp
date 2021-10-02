#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> sd;
    deque<int> dq;
    for(int i=0;i<nums.size();i++){
        if(!dq.empty() && dq.front()==i-k){
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()]<nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1){
            sd.push_back(nums[dq.front()]);
        }
    }  
    return sd;
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
        int k;
        cin>>k;
        vector<int> b=maxSlidingWindow(a,k);
        for(int i=0;i<b.size();i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
