#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int activitySelection(vector<int> start, vector<int> end, int n){
    vector<pair<int,int>> act;
    for(int i=0;i<n;i++){
        act.push_back({end[i],start[i]});
    }
    sort(act.begin(),act.end());
    int a=1;
    int d=act[0].first;
    for(int i=1;i<n;i++){
        if(act[i].second>d){
            a+=1;
            d=act[i].first;
        }
    }
    return a;
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
        vector<int> b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        cout<<activitySelection(a,b,n)<<endl;
    }
    return 0;
}
