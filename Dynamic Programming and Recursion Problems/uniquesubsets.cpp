#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void makeuniqueset(vector<int> a1,vector<int> a2,set<vector<int>> &t){
    if(a1.size()==0){
        t.insert(a2);
        return;
    }
    vector<int> k=a2;
    k.push_back(a1.front());
    a1.erase(a1.begin());
    makeuniqueset(a1,a2,t);
    makeuniqueset(a1,k,t);
}
vector<vector<int>> AllSubsets(vector<int> arr, int n){
    set<vector<int>> t;
    vector<int> a2;
    sort(arr.begin(),arr.end());
    makeuniqueset(arr,a2,t);
    vector<vector<int>> r;
    for(auto it:t){
        r.push_back(it);
    }
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
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<vector<int>> v=AllSubsets(arr,n);
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
