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
void helper(TreeNode* root,int k,unordered_set<int> &st,bool &flag){
    if(!root){
        return;
    }
    helper(root->left,k,st,flag);
    if(st.find(k-root->val)!=st.end()){
        flag=true;
        return;
    }
    st.insert(root->val);
    helper(root->right,k,st,flag);
}
bool findTarget(TreeNode* root, int k) {
    unordered_set<int> st;
    bool flag=false;
    helper(root,k,st,flag);
    return flag;
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
        cout<<findTarget(root,2)<<endl;
    }
    return 0;
}
