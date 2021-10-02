#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int kthElement(int arr1[], int arr2[], int n, int m, int k){
    if(n>m){
        return kthElement(arr2,arr1,m,n,k);
    } 
    int l=max(0,k-m);
    int h=min(k,n);
    while(l<=h){
        int m1=(l+h)/2;
        int m2=k-m1;
        int l1=m1==0 ? INT_MIN:arr1[m1-1];
        int l2=m2==0 ? INT_MIN:arr2[m2-1];
        int r1=m1==n ? INT_MAX:arr1[m1];
        int r2=m2==m ? INT_MAX:arr2[m2];
        if(l1<=r2 && l2<=r1){
            return max(l1,l2);
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
        int a[n];
        int b[m];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        int k;
        cin>>k;
        cout<<kthElement(a,b,n,m,k)<<endl;
    }
    return 0;
}
