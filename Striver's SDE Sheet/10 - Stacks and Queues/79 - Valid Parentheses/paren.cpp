#include<bits/stdc++.h>
using namespace std;
#define ll long long int
bool isValid(string s){
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(' or s[i]=='{' or s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(!st.empty() and st.top()=='('){
                st.pop();
            }
            else{
                return false;
            }
        }
        else if(s[i]==']'){
            if(!st.empty() and st.top()=='['){
                st.pop();
            }
            else{
                return false;
            }
        }
        else{
            if(!st.empty() and st.top()=='{'){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        string s;
        cin>>s;
        cout<<isValid(s)<<endl;
    }
    return 0;
}
