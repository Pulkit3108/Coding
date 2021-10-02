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
vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> lo;
    if(!root){
        return lo;
    }
    queue<TreeNode*> q;
    q.push(root);
    int lt=0;
    while(!q.empty()){
        vector<int> l;
        int s=q.size();
        for(int i=0;i<s;i++){
            TreeNode* t=q.front();
            q.pop();
            l.push_back(t->val);
            if(t->left){
                q.push(t->left);
            }
            if(t->right){
                q.push(t->right);
            }
        }
        if(lt&1){
            reverse(l.begin(),l.end());
        }
        lo.push_back(l);
        lt+=1;
    }
    return lo;
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
        vector<vector<int>> a=zigzagLevelOrder(root);
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[i].size();j++){
                cout<<a[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
