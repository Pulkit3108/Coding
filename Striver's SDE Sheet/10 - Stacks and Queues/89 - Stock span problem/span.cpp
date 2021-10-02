#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> calculateSpan(int price[], int n){
    vector<int> s(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && price[st.top()]<=price[i]){
            st.pop();
        }
        if(st.empty()){
            s[i]=i+1;
        }
        else{
            s[i]=(i-st.top());
        }
        st.push(i);
    }
    return s;
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
        vector<int> s=calculateSpan(a,n);
        for(int i=0;i<s.size();i++){
            cout<<s[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
