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
void recur(TreeNode* root,vector<int> &t){
    if(!root){
        return;
    }
    recur(root->left,t);
    t.push_back(root->val);
    recur(root->right,t);
}
vector<int> inorderTraversal(TreeNode* root){
    vector<int> od;
    if(!root){
        return od;
    }
    stack<TreeNode*> st;
    TreeNode* t=root;
    while(t || !st.empty()){
        while(t){
            st.push(t);
            t=t->left;
        }
        t=st.top();
        od.push_back(t->val);
        st.pop();
        t=t->right;
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
        vector<int> a=inorderTraversal(root);
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
