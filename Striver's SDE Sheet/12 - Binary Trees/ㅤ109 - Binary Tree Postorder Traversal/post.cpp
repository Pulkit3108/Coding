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
void post(TreeNode* root,vector<int> &t){
    if(root==nullptr){
        return;
    }
    post(root->left,t);
    post(root->right,t);
    t.push_back(root->val);
}
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> od;
    if(!root){
        return od;
    }
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    TreeNode* t=root;
    st1.push(t);
    while(!st1.empty()){
        t=st1.top();
        st1.pop();
        st2.push(t);
        if(t->left){
            st1.push(t->left);
        }
        if(t->right){
            st1.push(t->right);
        }
    }
    while(!st2.empty()){
        od.push_back(st2.top()->val);
        st2.pop();
    }
    return od;
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
        vector<int> a=postorderTraversal(root);
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
