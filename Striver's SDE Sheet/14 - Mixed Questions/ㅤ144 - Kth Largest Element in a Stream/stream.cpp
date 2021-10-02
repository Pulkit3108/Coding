#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> q;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
            if(q.size()>k){
                q.pop();
            }
        }
    }
    int add(int val) {
        q.push(val);
        if(q.size()>k){
            q.pop();
        }
        return q.top();
    }
};
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
