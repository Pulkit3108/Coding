#include<bits/stdc++.h>
using namespace std;
#define ll long long int
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    if(nums2.size()<nums1.size()){
        return findMedianSortedArrays(nums2,nums1);
    }
    int n=nums1.size();
    int m=nums2.size();
    int l=0;
    int h=n;
    while(l<=h){
        int m1=(l+h)/2;
        int m2=(n+m+1)/2-m1;
        int l1=m1==0 ? INT_MIN:nums1[m1-1];
        int l2=m2==0 ? INT_MIN:nums2[m2-1];
        int r1=m1==n ? INT_MAX:nums1[m1];
        int r2=m2==m ? INT_MAX:nums2[m2];
        if(l1<=r2 && l2<=r1){
            if((n+m)%2==0){
                return (max(l1,l2)+min(r1,r2))/2.0;
            }
            else{
                return max(l1,l2);
            }
        }
        else if(l1>r2){
            h=m1-1;
        }
        else{
            l=m1+1;
        }
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> b(m);
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        cout<<findMedianSortedArrays(a,b)<<endl;
    }
    return 0;
}
