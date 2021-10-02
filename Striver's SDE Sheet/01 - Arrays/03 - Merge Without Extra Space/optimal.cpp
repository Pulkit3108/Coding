#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int getgap(int g){
    if(g<=1){
        return 0;
    }
    return (g/2)+(g%2);
}
void merge(long long arr1[], long long arr2[], int n, int m) { 
    int g=n+m;
    int i;
    int j;
    g=getgap(g);
    while(g>0){
        for(i=0;i<n-g;i++){
            if(arr1[i]>arr1[i+g]){
                swap(arr1[i],arr1[i+g]);
            }
        }
        if(g>n){
            j=g-n;
        }
        else{
            j=0;
        }
        while(i<n && j<m){
            if(arr1[i]>arr2[j]){
                swap(arr1[i],arr2[j]);
            }
            i+=1;
            j+=1;
        }
        if(j<m){
            for(j=0;j<m-g;j++){
                if(arr2[j]>arr2[j+g]){
                    swap(arr2[j],arr2[j+g]);
                }
            }
        }
        g=getgap(g);
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
