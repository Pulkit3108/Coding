  
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int trap(vector<int>& height) {
    int l=0;
    int r=height.size()-1;
    int lm=0;
    int rm=0;
    int w=0;
    while(l<r){
        if(height[l]<=height[r]){
            if(height[l]>lm){
                lm=height[l];
            }
            else{
                w+=lm-height[l];
            }
            l+=1;
        }
        else{
            if(height[r]>rm){
                rm=height[r];
            }
            else{
                w+=rm-height[r];
            }
            r-=1;
        }
    }
    return w;
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
        cout<<trap(arr)<<endl;
    }
    return 0;
}
