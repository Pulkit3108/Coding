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
int getSum(TreeNode* root,int &s){
    if(!root){
        return 0;
    }
    int l=max(0,getSum(root->left,s));
    int r=max(0,getSum(root->right,s));
    s=max(s,root->val+l+r);
    return root->val+max(l,r);
}
int maxPathSum(TreeNode* root){
    int s=INT_MIN;
    getSum(root,s);
    return s;   
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        struct TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        cout<<maxPathSum(root)<<endl;
    }
    return 0;
}
