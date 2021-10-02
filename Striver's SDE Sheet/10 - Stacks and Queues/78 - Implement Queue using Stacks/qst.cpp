#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class MyQueue{
    stack<int> i,o;
public:
    MyQueue(){
        
    }
    void push(int x){
        i.push(x);
    }
    int pop(){
        int x=peek();
        o.pop();
        return x;
    }
    int peek(){
        if(o.empty()){
            while(!i.empty()){
                o.push(i.top());
                i.pop();
            }
        }
        return o.top();
    }
    bool empty(){
        return i.empty() && o.empty();
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        MyQueue q;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            q.push(x);
        }
        for(int i=0;i<n;i++){
            cout<<q.pop()<<" ";
        }
        cout<<endl;
    }
    return 0;
}
