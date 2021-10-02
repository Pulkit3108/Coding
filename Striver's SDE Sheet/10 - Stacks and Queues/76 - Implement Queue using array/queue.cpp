#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;
public:
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};
void MyQueue::push(int x){
    arr[rear++]=x;
}

int MyQueue::pop(){
    if(front!=rear){
        return arr[front++];
    }
    return -1;
}
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
