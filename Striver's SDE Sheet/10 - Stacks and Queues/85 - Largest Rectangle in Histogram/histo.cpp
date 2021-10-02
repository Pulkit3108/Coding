#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int largestRectangleArea(vector<int>& heights) {
    int ma=0;
    stack<int> st;
    for(int i=0;i<heights.size()+1;i++){
        while(!st.empty() && (i==heights.size() || heights[st.top()]>=heights[i])){
            int h=heights[st.top()];
            st.pop();
            int w;
            if(st.empty()){
                w=i;
            }
            else{
                w=i-st.top()-1;
            }
            ma=max(ma,h*w);
        }
        st.push(i);
    }
    return ma;
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
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<largestRectangleArea(a)<<endl;
    }
    return 0;
}
