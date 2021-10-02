#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct Job { 
    int id;     
    int dead; 
    int profit; 
};
static bool compare(Job a,Job b){
    return a.profit>b.profit;
}
vector<int> JobScheduling(Job arr[], int n) { 
    sort(arr,arr+n,compare);
    int m=0;
    for(int i=0;i<n;i++){
        m=max(arr[i].dead,m);
    }
    vector<int> s(m+1,-1);
    int c=0;
    int t=0;
    for(int i=0;i<n;i++){
        for(int j=arr[i].dead;j>0;j--){
            if(s[j]==-1){
                s[j]=arr[i].id;
                c+=1;
                t+=arr[i].profit;
                break;
            }
        }
    }
    vector<int> r;
    r.push_back(c);
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
        Job arr[n];
        for(int i=0;i<n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            arr[i].id=x;
            arr[i].dead=y;
            arr[i].profit=z;
        }
        vector<int> ans = JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;     
    }
    return 0;
}
