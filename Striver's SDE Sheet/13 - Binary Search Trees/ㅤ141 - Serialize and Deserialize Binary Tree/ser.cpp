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
class Codec{
public:
    string serialize(TreeNode* root){
        string s="";
        if(!root){
            return s;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* t=q.front();
            q.pop();
            if(!t){
                s.push_back('#');
            }
            else{
                s.append(to_string(t->val));
                q.push(t->left);
                q.push(t->right);
            }
            s.push_back(',');
        }
        return s;
    }
    TreeNode* deserialize(string data){
        if(data.size()==0){
            return nullptr;
        }
        stringstream t(data);
        string s; 
        getline(t,s,',');
        TreeNode *root=new TreeNode(stoi(s));
        queue<TreeNode*> q; 
        q.push(root); 
        while(!q.empty()) {
            TreeNode *c=q.front(); 
            q.pop(); 
            getline(t,s,',');
            if(s=="#") {
                c->left=nullptr; 
            }
            else{
                TreeNode* l=new TreeNode(stoi(s)); 
                c->left=l; 
                q.push(l); 
            }
            getline(t,s,',');
            if(s=="#"){
                c->right=nullptr; 
            }
            else{
                TreeNode* r=new TreeNode(stoi(s)); 
                c->right=r;
                q.push(r); 
            }
        }
        return root; 
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
