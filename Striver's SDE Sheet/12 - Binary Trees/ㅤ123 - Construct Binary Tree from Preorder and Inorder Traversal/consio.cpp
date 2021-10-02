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
TreeNode* helper(vector<int> &preorder, vector<int> &inorder, int is,int ie,int ps,int pe,unordered_map<int,int> &mp){
    if(is>ie || ps>pe){
        return nullptr;
    }
    TreeNode* root=new TreeNode(preorder[ps]);
    int i=mp[preorder[ps]];
    int j=i-is;
    root->left=helper(preorder,inorder,is,i-1,ps+1,ps+j,mp);
    root->right=helper(preorder,inorder,i+1,ie,ps+j+1,pe,mp);
    return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
    unordered_map<int,int> mp;
    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;
    }
    TreeNode* root=helper(preorder,inorder,0,inorder.size()-1,0,preorder.size()-1,mp);
    return root;
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
        vector<int> pro(n),ino(n);
        for(int i=0;i<n;i++){
            cin>>pro[i];
        }
        for(int i=0;i<n;i++){
            cin>>ino[i];
        }
        cout<<buildTree(pro,ino)->val<<endl;
    }
    return 0;
}
