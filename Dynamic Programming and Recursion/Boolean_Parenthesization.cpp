#include<bits/stdc++.h>
using namespace std;
#define ll long long int
// unordered_map<string, int> mp;
static int dp[1001][1001][2];
int evaluate(string s, int i, int j, bool x){
    if(i==j){
        if(x){
            return(s[i]=='T');
        }
        else{
            return(s[i]=='F');
        }
    }
    if(dp[i][j][x]!=-1){
        return(dp[i][j][x]);
    }
    // string t=to_string(i);
    // t.push_back(' ');
    // t.append(to_string(j));
    // t.push_back(' ');
    // t.append(to_string(x));
    // if(mp.find(t)!=mp.end()){
    //     return(mp[t]);
    // }
    int k;
    int f=0;
    for(k=i+1;k<j;k+=2){
        // int lt=evaluate(s,i,k-1,true);
        // int lf=evaluate(s,i,k-1,false);
        // int rt=evaluate(s,k+1,j,true);
        // int rf=evaluate(s,k+1,j,false);
        int lf,lt,rt,rf;
        if(dp[i][k-1][1]==-1){ 
            lt=evaluate(s,i,k-1,true);
        }
        else{ 
            lt=dp[i][k-1][1];
        }
        if(dp[i][k-1][0]==-1){ 
            lf=evaluate(s,i,k-1,false);
        }
        else{ 
            lf=dp[i][k-1][0];
        }
        if(dp[k+1][j][1]==-1){
            rt=evaluate(s,k+1,j,true);
        }
        else{ 
            rt=dp[k+1][j][1];
        }
        if(dp[k+1][j][0]==-1){ 
            rf=evaluate(s,k+1,j,false);
        }
        else{ 
            rf=dp[k+1][j][0];
        }
        if(s[k]=='&'){
            if(x){
                f+=(lt*rt);
            }
            else{
                f+=(lt*rf)+(lf*rt)+(lf*rf);
            }
        }
        else if(s[k]=='|'){
            if(x){
                f+=(lt*rf)+(lf*rt)+(rt*lt);
            }
            else{
                f+=(lf*rf);
            }
        }
        else if(s[k]=='^'){
            if(x){
                f+=(lf*rt)+(rf*lt);
            }
            else{
                f+=(lt*rt)+(rf*lf);
            }
        }
        dp[i][j][x]=f%1003;
    }
    return(f%1003);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        memset(dp,-1,sizeof(dp));
        // mp.clear();
        cout<<evaluate(s,0,s.size()-1,true)<<endl;
    }
    return 0;
}
