#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int maxProfit(vector<int>& prices) {
    int p=0;
    int m=prices[0];
    for(int i=1;i<prices.size();i++){
        m=min(m,prices[i]);
        p=max(p,prices[i]-m);
    }
    return p;
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
        cout<<maxProfit(a)<<endl;  
    }
    return 0;
}
