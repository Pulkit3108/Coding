#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int p=1e9+7;
vector<int> search(string pattern,string text){
    string t=pattern+to_string('$')+text;
    int n=t.size();
    vector<int> Z(n,0);
    int l=0;
    int r=0;
    for(int i=1;i<n;i++){
        if(i>r){
            l=r=i;
            while(r<n && t[r-l]==t[r]){
                r+=1;
            }
            Z[i]=r-l;
            r-=1;
        }
        else{
            int k=i-l;
            if(Z[k]<r-i+1){
                Z[i]=Z[k];
            }
            else{
                l=i;
                while(r<n && t[r-l]==t[r]){
                    r+=1;
                }
                Z[i]=r-l;
                r-=1;
            }
        }
    }
    vector<int> m;
    for(int i=0;i<n;i++){
        if(Z[i]==pattern.size()){
            m.push_back(i-pattern.size()-1);
        }
    }
    return m;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        string s,t;
        cin>>s>>t;
        vector<int> a=search(s,t);
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
