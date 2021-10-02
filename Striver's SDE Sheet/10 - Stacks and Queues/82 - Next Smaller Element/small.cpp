#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> nextSmallerElements(vector<int>& nums){
    int n=nums.size();
    stack<int> st;
    vector<int> a(n);
    for(int i=2*n-1;i>=0;i--){
        while(!st.empty() && st.top()>=nums[i%n]){
            st.pop();
        }
        if(i<n){
            if(!st.empty()){
                a[i]=st.top();
            }
            else{
                a[i]=-1;
            }
        }
        st.push(nums[i%n]);
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
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> b=nextGreaterElements(a);
        for(int i=0;i<n;i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
