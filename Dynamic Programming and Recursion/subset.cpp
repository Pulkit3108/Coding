/*
Given an array of integers(positive as well as negative) ,select some elements from this array(select a subset) such that:-
    Sum of those elements is maximum(Sum of the subset is maximum) .
    No 2 elements in the subset should be consecutive.
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
    int a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> dp(1000);
    dp[0]=0;
    dp[1]=max(a[0],dp[0]);
    i=1;
    while(i<n){
        dp[i+1]=max(a[i]+dp[i-1],dp[i]);
        i+=1;
    }
    cout<<dp[n]<<" ";
    return 0;
}
