/*
We are given four arrays of size-’N’ . At each index-’i’ , we have to select “1” element out of the 4 given elements,with a special condition that if you select the number from say, j-th array at index-’i’ ,then you can’t select an element from j-th array again at index-’i+1' , can you maximize the sum ?
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int i;
    int a1[n],a2[n],a3[n],a4[n];
    for(i=0;i<n;i++){
        cin>>a1[i];
    }
    for(i=0;i<n;i++){
        cin>>a2[i];
    }
    for(i=0;i<n;i++){
        cin>>a3[i];
    }
    for(i=0;i<n;i++){
        cin>>a4[i];
    }
    vector<int> dp1(1000);
    vector<int> dp2(1000);
    vector<int> dp3(1000);
    vector<int> dp4(1000);
    dp1[0]=0;
    dp2[0]=0;
    dp3[0]=0;
    dp4[0]=0;
    dp1[1]=a1[0];
    dp2[1]=a2[0];
    dp3[1]=a3[0];
    dp4[1]=a4[0];        
    i=1;
    while(i<n){
        dp1[i+1]=a1[i]+max({dp2[i],dp3[i],dp4[i]});
        dp2[i+1]=a2[i]+max({dp1[i],dp3[i],dp4[i]});
        dp3[i+1]=a3[i]+max({dp2[i],dp1[i],dp4[i]});
        dp4[i+1]=a4[i]+max({dp2[i],dp3[i],dp1[i]});
        i+=1;
    }
    cout<<max({dp1[n],dp2[n],dp3[n],dp4[n]});
    return 0;
}
