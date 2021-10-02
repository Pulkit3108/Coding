#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool allocate(vector<int> &a,int b,int m){
    int s=1;
    int p=0;
    for(int i=0;i<a.size();i++){
        if(p+a[i]>m){
            s+=1;
            p=a[i];
        }
        else{
            p+=a[i];
        }
    }
    if(s>b){
        return false;
    }
    else{
        return true;
    }
}
int books(vector<int> &a, int b){
    if(b>a.size()){
        return -1;
    }
    int l=*max_element(a.begin(),a.end());
    int h=accumulate(a.begin(),a.end(),0);
    int s=-1;
    while(l<=h){
        int m=(l+h)>>1;
        if(allocate(a,b,m)){
            s=m;
            h=m-1;
        }
        else{
            l=m+1;
        }
    }
    return s;
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
        int b;
        cin>>b;
        cout<<books(a,b)<<endl;
    }
    return 0;
}
