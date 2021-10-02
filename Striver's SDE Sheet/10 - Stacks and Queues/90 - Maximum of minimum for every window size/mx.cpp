#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> maxOfMin(int arr[], int n){       
    vector<int> pse(n,-1);
    stack<int> pst;
    for(int i=0;i<n;i++){
        while(!pst.empty() && arr[pst.top()]>=arr[i]){
            pst.pop();
        }
        if(!pst.empty()){
            pse[i]=pst.top();
        }
        pst.push(i);
    }
    vector<int> nse(n,n);
    stack<int> nst;
    for(int i=n-1;i>=0;i--){
        while(!nst.empty() && arr[nst.top()]>=arr[i]){
            nst.pop();
        }
        if(!nst.empty()){
            nse[i]=nst.top();
        }
        nst.push(i);
    }
    vector<int> t(n+1,0);
    for(int i=0;i<n;i++){
        int l=nse[i]-pse[i]-1;
        t[l]=max(t[l],arr[i]);
    }
    for(int i=n-1;i>=0;i--){
        t[i]=max(t[i],t[i+1]);
    }
    t.erase(t.begin());
    return t;
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
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int> s=maxOfMin(a,n);
        for(int i=0;i<s.size();i++){
            cout<<s[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
