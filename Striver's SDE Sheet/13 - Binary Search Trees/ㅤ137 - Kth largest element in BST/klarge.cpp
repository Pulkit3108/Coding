
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
void helper(Node* root,int &k,int &c){
    if(!root){
        return;
    }
    helper(root->right,k,c);
    k-=1;
    if(k==0){
        c=root->data;
        return;
    }
    helper(root->left,k,c);
}
int kthLargest(Node *root, int k){
    int l=0;
    helper(root,k,l);
    return l;
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
        cout<<kthLargest(root,1);
    }
    return 0;
}
