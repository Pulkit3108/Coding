#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int maxMeetings(int start[], int end[], int n){
    int m=1;
    vector<pair<int,int>> meet;
    for(int i=0;i<n;i++){
        meet.push_back({end[i],start[i]});
    }
    sort(meet.begin(),meet.end());
    int s=meet[0].first;
    for(int i=1;i<n;i++){
        if(s<meet[i].second){
            m+=1;
            s=meet[i].first;
        }
    }
    return m;
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
        int arr1[n],arr2[n];
        for(int i=0;i<n;i++){
            cin>>arr1[i];
        }
        for(int i=0;i<n;i++){
            cin>>arr2[i];
        }
        cout<<maxMeetings(arr1,arr2,n)<<endl;
    }
    return 0;
}
