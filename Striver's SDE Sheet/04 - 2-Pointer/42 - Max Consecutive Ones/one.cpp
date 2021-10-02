#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int findMaxConsecutiveOnes(vector<int>& nums){
    int c=0;
    int m=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==1){
            c+=1;
        }
        else{
            c=0;
        }
        m=max(m,c);
    }   
    return m;
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
        cout<<findMaxConsecutiveOnes(arr)<<endl;
    }
    return 0;
}
