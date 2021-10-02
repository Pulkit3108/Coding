#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
bool helper(Node* l,Node* r){
    if(!l || !r){
        return l==r;
    }
    if(l->data!=r->data){
        return false;
    }
    else{
        return helper(l->left,r->right) && helper(l->right,r->left);
    }
}
bool isMirror(struct Node* root){
    if(!root){
        return true;
    }
    return helper(root->left,root->right);
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
        cout<<isMirror(root)<<endl;
    }
    return 0;
}
