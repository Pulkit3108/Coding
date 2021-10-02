/*
We are given ‘2’ arrays . Select some elements from both of these arrays (select a subset) such that:-

    Sum of those elements is maximum(Sum of the subset is maximum).
    No 2 elements in the subset should be consecutive.(Note:-If you select, say 5'th element from Array-1, 
    then you are not allowed to select 4'th element from either Array-1 or Array-2 :-) )
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int i;
    int a[n],b[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<n;i++){
        cin>>b[i];
    }
    vector<int> dp(1000);
    dp[0]=0;
    dp[1]=max(a[0],b[0]);
    i=1;
    while(i<n){
        dp[i+1]=max(max(a[i],b[i])+dp[i-1],dp[i]);
        i+=1;
    }
    cout<<dp[n]<<" ";
    return 0;
}
