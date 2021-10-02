#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class SortedStack{
public:
    stack<int> s;
    void sort();
};
void SortedStack :: sort(){
    stack<int> st;
    while(!s.empty()){
        st.push(s.top());
        s.pop();
    }
    while(!st.empty()){
        int t=st.top();
        st.pop();
        while(!s.empty() && s.top()>t){
            st.push(s.top());
            s.pop();
        }
        s.push(t);
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
        SortedStack st;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            st.s.push(x);
        }
        st.sort();
        for(int i=0;i<n;i++){
            cout<<st.s.top();
            st.s.pop();
        }
        cout<<endl;
    }
    return 0;
}
