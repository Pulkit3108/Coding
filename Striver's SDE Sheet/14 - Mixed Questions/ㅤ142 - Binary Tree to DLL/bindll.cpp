#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct Node{
    int data;
    struct Node *left, *right;
    Node(int x){
        data=x;
        left=nullptr;
        right=nullptr;
    }
};
void helper(Node* root,Node* &h,Node* &p){
    if(!root){
        return;
    }
    helper(root->left,h,p);
    root->left=p;
    if(!p){
        h=root;
    }   
    else{
        p->right=root;
    }
    p=root;
    helper(root->right,h,p);
}
Node * bToDLL(Node *root){ 
    Node* h=nullptr;
    Node* p=nullptr;
    helper(root,h,p);
    return h;
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
    }
    return 0;
}
