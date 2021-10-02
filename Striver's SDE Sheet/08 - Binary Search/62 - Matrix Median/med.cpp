#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int getupperbound(vector<int> &a,int t){
    int l=0;
    int h=a.size()-1;
    while(l<=h){
        int m=(l+h)/2;
        if(a[m]<=t){
            l=m+1;
        }
        else{
            h=m-1;
        }
    }
    return l;
}
int findMedian(vector<vector<int>> &a) {
    int l=1;
    int h=1e9;
    int n=a.size();
    int m=a[0].size();
    while(l<=h){
        int md=(l+h)/2;
        int c=0;
        for(int i=0;i<n;i++){
            c+=getupperbound(a[i],md);
        }
        if(c<=(n*m)/2){
            l=md+1;
        }
        else{
            h=md-1;
        }
    }
    return l;
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
        vector<vector<int>> a;
        for(int i=0;i<n;i++){
            vector<int> t(m);
            for(int j=0;j<m;j++){
                cin>>t[j];
            }
            a.push_back(t);
        }
        cout<<findMedian(a)<<endl;
        
    }
    return 0;
}
