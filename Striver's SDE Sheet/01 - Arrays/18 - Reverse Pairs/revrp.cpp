#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int merge(vector<int> &a,int l,int r,int m){
    int c=0;
    int i,j;
    j=m+1;
    for(i=l;i<=m;i++){
        while(j<=r and a[i]>2LL*a[j]){
            j+=1;
        }
        c+=j-m-1;
    }
    vector<int> t;
    i=l;
    j=m+1;
    while(i<=m && j<=r){
        if(a[i]<=a[j]){
            t.push_back(a[i]);
            i+=1;
        }
        else{
            t.push_back(a[j]);
            j+=1;
        }
    }
    while(i<=m){
        t.push_back(a[i]);
        i+=1; 
    }
    while(j<=r){
        t.push_back(a[j]);
        j+=1;
    }
    for(i=l;i<=r;i++){
        a[i]=t[i-l];
    }
    return c;
}
int mergesort(vector<int> &a,int l,int r){
    if(l>=r){
        return 0;
    }
    int m=(l+r)/2;
    int c=mergesort(a,l,m);
    c+=mergesort(a,m+1,r);
    c+=merge(a,l,r,m);
    return c;
}
int reversePairs(vector<int>& nums) {
    return mergesort(nums,0,nums.size()-1);
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
        cout<<reversePairs(a)<<endl;
    }
    return 0;
}
