#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> majorityElement(vector<int>& nums) {
    int e1=nums[0];
    int e2=-1;
    int c1=1;
    int c2=0;
    for(int i=1;i<nums.size();i++){
        if(nums[i]==e1){
            c1+=1;
        }
        else if(nums[i]==e2){
            c2+=1;
        }
        else if(c1==0){
            e1=nums[i];
            c1+=1;
        }
        else if(c2==0){
            e2=nums[i];
            c2+=1;
        }
        else{
            c1-=1;
            c2-=1;
        }
    }
    c1=0,c2=0;
    vector<int> m;
    for(int i=0;i<nums.size();i++){
        if(e1==nums[i]){
            c1+=1;
        }
        else if(e2==nums[i]){
            c2+=1;
        }
    }
    if(c1>nums.size()/3){
        m.push_back(e1);
    }
    if(c2>nums.size()/3){
        m.push_back(e2);
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
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> b=majorityElement(a);
        for(int i=0;i<b.size();i++){
            cout<<b[i]<<" ";
        }
        
    }
    return 0;
}
