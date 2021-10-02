#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void parenthesis2(int o,int c,string t,vector<string> &r){
    if(o==0 and c==0){
        r.push_back(t);
        return;
    }
    if(o!=0){
        string t1=t;
        t1.push_back('(');
        parenthesis(o-1,c,t1,r);
    }
    if(c>o){
        string t2=t;
        t2.push_back(')');
        parenthesis(o,c-1,t2,r);
    }

void parenthesis(int o,int c,string t,vector<string> &r){
    if(o==0 and c==0){
        r.push_back(t);
        return;
    }
    if(o==c){
        t.push_back('(');
        parenthesis(o-1,c,t,r);
    }
    else if(o==0){
        t.push_back(')');
        parenthesis(o,c-1,t,r);
    }
    else{
        string n=t;
        t.push_back('(');
        n.push_back(')');
        parenthesis(o-1,c,t,r);
        parenthesis(o,c-1,n,r);
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> r;
    string t="";
    parenthesis(n,n,t,r);
    return r;
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
        vector<string> m=generateParenthesis(n);
        for(int i=0;i<m.size();i++){
            cout<<m[i]<<" ";
        }
    }
    return 0;
}
