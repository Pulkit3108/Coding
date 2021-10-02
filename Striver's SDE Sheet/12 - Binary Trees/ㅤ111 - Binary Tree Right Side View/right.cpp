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
void rightrecur(TreeNode* root,int l,vector<int> &t){
    if(root==nullptr){
        return;
    }
    if(l==t.size()){
        t.push_back(root->val);
    }
    rightrecur(root->right,l+1,t);
    rightrecur(root->left,l+1,t);
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> rv;
    rightrecur(root,0,rv);
    return rv;
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
        vector<int> a=rightSideView(root);
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
