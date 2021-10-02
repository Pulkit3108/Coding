#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool cow(int a[],int n,int c,int m){
    int s=1;
    int d=a[0];
    for(int i=1;i<n;i++){
        if(a[i]-d>=m){
            s+=1;
            d=a[i];
        }
    }
    if(s<c){
        return false;
    }
    else{
        return true;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n,c;
        cin>>n>>c;
        int a[n];
        for(int i=0;i<n;i++){ 
            cin>>a[i]; 
        }
        sort(a,a+n);
        int l=1;
        int h=a[n-1]-a[0];
        while(l<=h){
            int m=(l+h)/2;
            if(cow(a,n,c,m)){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        cout<<h<<endl;
    }
    return 0;
}
