#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct Item{
    int value;
    int weight;
};
static bool compare(Item a,Item b){
    double ia=(double)a.value/a.weight;
    double ib=(double)b.value/b.weight;
    return ia>ib;
}
double fractionalKnapsack(int W, Item arr[], int n){
    sort(arr,arr+n,compare);
    double p=0;
    for(int i=0;i<n;i++){
        if(W>=arr[i].weight){
            p+=arr[i].value;
            W-=arr[i].weight;
        }
        else{
            p+=W*((double)arr[i].value/arr[i].weight);
            break;
        }
    }
    return p;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        int n, w;
        cin>>n>>w;
        Item arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i].value>>arr[i].weight;
        }
        cout<<fractionalKnapsack(w,arr,n)<<endl;       
    }
    return 0;
}
