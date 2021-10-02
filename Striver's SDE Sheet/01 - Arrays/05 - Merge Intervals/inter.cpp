#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> r;
    sort(intervals.begin(),intervals.end());
    vector<int> t(intervals[0]);
    for(int i=1;i<intervals.size();i++){
        if(t[1]>=intervals[i][0]){
            t[1]=max(t[1],intervals[i][1]);
        }
        else{
            r.push_back(t);
            t=intervals[i];
        }
    }
    r.push_back(t);
    return r;
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
        vector<vector<int>> a;
        for(int i=0;i<n;i++){
            vector<int> x(2);
            for(int j=0;j<2;j++){
                cin>>x[j];
            }
            a.push_back(x);
        }
        vector<vector<int>> m=merge(a);
        for(int i=0;i<m.size();i++){
            for(int j=0;j<2;j++){
                cout<<m[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
