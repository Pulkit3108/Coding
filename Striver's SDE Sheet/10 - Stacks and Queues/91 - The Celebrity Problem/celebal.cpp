#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int celebrity(vector<vector<int>>& M, int n){
    stack<int> st;
    for(int i=0;i<n;i++){
        st.push(i);
    }
    while(st.size()>1){
        int i=st.top();
        st.pop();
        int j=st.top();
        st.pop();
        if(M[i][j]==1){
            st.push(j);
        }
        else{
            st.push(i);
        }
    }
    int k=st.top();
    bool flag=true;
    for(int i=0;i<n;i++){
        if(i!=k){
            if(M[i][k]==0 || M[k][i]==1){
                flag=false;
                break;
            }
        }
    }
    if(flag){
        return k;
    }
    else{
        return -1;
    }
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
            vector<int> b(n); 
            for(int j=0;j<n;j++){
                cin>>b[i];
            }
            a.push_back(b);
        }
        cout<<celebrity(a,n)<<endl;
    }
    return 0;
}
