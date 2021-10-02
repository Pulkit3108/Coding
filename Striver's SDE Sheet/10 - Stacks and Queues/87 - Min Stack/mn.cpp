#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class MinStack {
    stack<pair<int,int>> st;
public:
    MinStack() {
    }
    void push(int val) {
        int m;
        if(st.empty()){
            m=val;
        }
        else{
            m=min(st.top().second,val);
        }
        st.push({val,m});
    }
    void pop() {
        st.pop();
    }
    int top() {
        return st.top().first;
    }
    int getMin() {
        return st.top().second;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        MinStack st;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            st.push(x);
        }
        cout<<st.top()<<" "<<st.getMin()<<endl;
        
    }
    return 0;
}
