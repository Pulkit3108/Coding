#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct Node{
    int key;
    struct Node *left, *right;
    Node(int x){
        key=x;
        left=nullptr;
        right=nullptr;
    }
};
void findPreSuc(Node* root, Node* &pre, Node* &suc, int key){
    pre=nullptr;
    suc=nullptr;
    while(root && root->key!=key){
        if(root->key<key){
            pre=root;
            root=root->right;
        }
        else{
            suc=root;
            root=root->left;
        }
    }
    if(!root){
        return;
    }
    if(root->right){
        Node* t=root->right;
        while(t->left){
            t=t->left;
        }
        suc=t;
    }
    if(root->left){
        Node* t=root->left;
        while(t->right){
            t=t->right;
        }
        pre=t;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        struct Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
        struct Node* p = nullptr;
        struct Node* q = nullptr;
        findPreSuc(root,p,q,5);
    }
    return 0;
}
