/*
Find the number of different ways in which groups (partitions) can be formed of a set and the maximum size of the group is 2?
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> dp(1000);
    dp[0]=1;
    dp[1]=1;
    int i=2;
    while(i<=n){
        dp[i]=dp[i-1]+((i-1)*dp[i-2]);
        i+=1;
    }
    cout<<dp[n]<<" ";
    return 0;
}
