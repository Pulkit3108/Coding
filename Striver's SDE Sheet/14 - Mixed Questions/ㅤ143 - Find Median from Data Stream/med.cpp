#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class MedianFinder{
public:
    priority_queue<int> q1;
    priority_queue<int,vector<int>,greater<int>> q2;
    MedianFinder(){
    }
    void addNum(int num){
        if(q1.empty() || q1.top()>num){
            q1.push(num);
        }
        else{
            q2.push(num);
        }
        if(q1.size()>q2.size()+1){
            q2.push(q1.top());
            q1.pop();
        }
        if(q2.size()>q1.size()+1){
            q1.push(q2.top());
            q2.pop();
        }
    }
    double findMedian(){
        if(q1.size()==q2.size()){
            return (q1.top()+q2.top())/2.0;
        }
        else{
            return q1.size()>q2.size()?q1.top():q2.top();
        }
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){

    }
    return 0;
}
