#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* helper(vector<int> &nums,int l,int h){
    if(l>h){
        return nullptr;
    }
    int m=(l+h)/2;
    TreeNode* root=new TreeNode(nums[m]);
    root->left=helper(nums,l,m-1);
    root->right=helper(nums,m+1,h);
    return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums,0,nums.size()-1); 
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<sortedArrayToBST(a)->val<<endl;
    }
    return 0;
}
