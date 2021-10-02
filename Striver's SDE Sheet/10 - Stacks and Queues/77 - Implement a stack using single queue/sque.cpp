#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class Stack{
    queue<int>q;
public:
    void push(int val);
    void pop();
    int top();
    bool empty();
};
void Stack::push(int val){
    int n=q.size();
    q.push(val);
    for(int i=0;i<n;i++){
        q.push(q.front());
        q.pop();
    }
}
void Stack::pop(){
    if(q.empty()){
        cout<<"Queue is empty";
    }
    else{
        q.pop();
    }
}
int  Stack::top(){
    if(q.empty()){
        return -1;
    }
    else{
        return q.front();
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        Stack st;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            st.push(x);
        }
        for(int i=0;i<n;i++){
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;
    }
    return 0;
}
