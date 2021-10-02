#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int majorityElement(vector<int>& nums){
    int e=nums[0];
    int c=1;
    for(int i=1;i<nums.size();i++){
        if(c==0){
            e=nums[i];
        }
        if(e==nums[i]){
            c+=1;
        }
        else{
            c-=1;
        }
    }
    return e;
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
        cout<<majorityElement(a)<<endl; 
    }
    return 0;
}