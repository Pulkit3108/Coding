#include<bits/stdc++.h>
using namespace std;
#define ll long long int
string convertToRoman(int n){
    string r[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int c[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string s="";
    for(int i=12;i>=0;i--){
        while(n>=c[i]){
            s=s+r[i];
            n-=c[i];
        }
    }
    return s;
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
        cout<<convertToRoman(n)<<endl;
              
    }
    return 0;
}
