#include<bits/stdc++.h>
using namespace std;
#define ll long long int
void findMin(int V){ 
    int deno[]={1,2,5,10,20,50,100,500,1000};
    vector<int> coin;
    for(int i=8;i>=0;i--){
        while(V>=deno[i]){
            coin.push_back(deno[i]);
            V-=deno[i];
        }
    }
    for(int i=0;i<coin.size();i++){
        cout<<coin[i]<<" ";
    }
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        int V;
        cin>>V;
        findMin(V);
    }
    return 0;
}
