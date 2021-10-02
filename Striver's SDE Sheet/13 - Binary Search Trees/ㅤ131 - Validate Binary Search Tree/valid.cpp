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

bool helper(TreeNode* root,TreeNode* mx,TreeNode* mn){
    if(!root){
        return true;
    }
    if((mn && root->val<=mn->val) || (mx && root->val>=mx->val)){
        return false;
    }
    return helper(root->left,root,mn) && helper(root->right,mx,root);
}
bool isValidBST(TreeNode* root){
    return helper(root,nullptr,nullptr);
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
        cout<<isValidBST(root)<<endl;
    }
    return 0;
}
