#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int *findTwoElement(int *arr, int n) {
    int x=arr[0];
    for(int i=1;i<n;i++){
        x=x^arr[i];
    }
    for(int i=1;i<n+1;i++){
        x=x^i;
    }
    x=x&(~(x-1));
    int b1=0;
    int b2=0;
    for(int i=0;i<n;i++){
        if(x&arr[i]){
            b1=b1^arr[i];
        }
        else{
            b2=b2^arr[i];
        }
    }
    for(int i=1;i<n+1;i++){
        if(x&i){
            b1=b1^i;
        }
        else{
            b2=b2^i;
        }
    }
    for(int i=0;i<n;i++){
        if(b2==arr[i]){
            swap(b1,b2);
            break;
        }
    }
    int* b=new int[2];
    b[0]=b1;
    b[1]=b2;
    return b;
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
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int* b=findTwoElement(arr,n);
        cout<<"Repeating : "<<b[0]<<endl<<"Missing : "<<b[1];
    }
    return 0;
}
