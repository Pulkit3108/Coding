#include<bits/stdc++.h>
using namespace std;
#define ll long long int
long long int merge(long long a[],long long t[],long long l,long long r,long long m){
    long long i,j,k;
    long long c=0;
    i=l;
    j=m;
    k=l;
    while((i<=m-1) && (j<=r)){
        if(a[i]<=a[j]){
            t[k]=a[i];
            i+=1;
        }
        else{
            c+=m-i;
            t[k]=a[j];
            j+=1;
        }
        k+=1;
    }
    while(i<=m-1){
        t[k]=a[i];
        k+=1;
        i+=1;
    }
    while(j<=r){
        t[k]=a[j];
        k+=1;
        j+=1;
    }
    for(i=l;i<=r;i++){
        a[i]=t[i];
    }
    return c;
}
long long int mergesort(long long a[],long long t[],long long l,long long r){
    long long m;
    long long c=0;
    if(l<r){
        m=(l+r)/2;
        c+=mergesort(a,t,l,m);
        c+=mergesort(a,t,m+1,r);
        c+=merge(a,t,l,r,m+1);
    }
    return c;
}

long long int inversionCount(long long arr[], long long N){
    long long t[N];
    return mergesort(arr,t,0,N-1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        long long n;
        cin>>n;
        long long arr[n];
        for(long long i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<inversionCount(arr,n)<<endl;  
    }
    return 0;
}
