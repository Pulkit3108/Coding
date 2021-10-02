#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void merge(long long arr1[], long long arr2[], int n, int m) { 
    for(int i=0;i<n;i++){
        if(arr1[i]>arr2[0]){
            swap(arr1[i],arr2[0]);
            int k;
            long long s=arr2[0];
            for(k=1;(k<m && arr2[k]<s);k++){
                arr2[k-1]=arr2[k];
            } 
            arr2[k-1]=s;
        }
    }
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
        long long arr1[n],arr2[m];
        for(int i=0;i<n;i++){
            cin>>arr1[i];
        }
        for(int i=0;i<m;i++){
            cin>>arr2[i];
        }
        merge(arr1,arr2,n,m);
        for(int i=0;i<n;i++){
            cout<<arr1[i]<<" ";
        }
        for(int i=0;i<m;i++){
            cout<<arr2[i]<<" ";
        }
        
    }
    return 0;
}
