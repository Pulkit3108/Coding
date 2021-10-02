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
int getdiameter(TreeNode* root, int &d){
    if(!root){
        return 0;
    }
    int lh=getdiameter(root->left,d);
    int rh=getdiameter(root->right,d);
    d=max(d,lh+rh);
    return 1+max(lh,rh);
}
int diameterOfBinaryTree(TreeNode* root){
    int d=0;
    getdiameter(root,d);
    return d;
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
        cout<<diameterOfBinaryTree(root)<<endl;
    }
    return 0;
}
