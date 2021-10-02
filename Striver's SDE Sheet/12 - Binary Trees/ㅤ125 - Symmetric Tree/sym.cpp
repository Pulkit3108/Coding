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
bool helper(TreeNode* l,TreeNode* r){
    if(!l && !r){
        return true;
    }
    if(!l || !r || l->val!=r->val){
        return false;
    }
    else{
        return helper(l->left,r->right) && helper(l->right,r->left);
    }
}
bool isSymmetric(TreeNode* root) {
    return helper(root->left,root->right);
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
        cout<<isSymmetric(root)<<endl;
    }
    return 0;
}
