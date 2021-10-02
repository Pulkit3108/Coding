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
class BSTIterator{
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root){
        put(root);
    }
    int next(){
        TreeNode* t=st.top();
        st.pop();
        put(t->right);
        return t->val;
    }
    bool hasNext(){
        return !st.empty();
    }
    void put(TreeNode* root){
        TreeNode* t=root;
        while(t){
            st.push(t);
            t=t->left;
        }
    }
};
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
    }
    return 0;
}
