#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int findDuplicate(vector<int>& nums){
    int s=nums[0];
    int f=nums[0];
    do{
        s=nums[s];
        f=nums[nums[f]];
    }while(s!=f);
    f=nums[0];
    while(s!=f){
        s=nums[s];
        f=nums[f];
    }
    return s;
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
        cout<<findDuplicate(arr)<<endl;
    }
    return 0;
}
