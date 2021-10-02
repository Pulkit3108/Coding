#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void tor(int N, int from, int to, int aux, long long &c){
    if(N==1){
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        c+=1;
        return;
    }
    tor(N-1,from,aux,to,c);
    c+=1;
    cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
    tor(N-1,aux,to,from,c);
}
long long toh(int N, int from, int to, int aux) {
    long long c=0;
    tor(N,from,to,aux,c);
    return c;
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
        cout<<toh(n,1,3,2)<<endl;
    }
    return 0;
}
