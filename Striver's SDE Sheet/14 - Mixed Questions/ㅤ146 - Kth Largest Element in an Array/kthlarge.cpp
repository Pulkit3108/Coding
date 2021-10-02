#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int findKthLargest(vector<int>& nums, int k){
    priority_queue<int,vector<int>,greater<int>> q;
    for(auto &it:nums){
        q.push(it);
        if(q.size()>k){
            q.pop();
        }
    }   
    return q.top();
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){

    }
    return 0;
}
