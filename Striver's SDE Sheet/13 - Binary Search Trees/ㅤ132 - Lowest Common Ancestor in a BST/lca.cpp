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
Node* LCA(Node *root, int n1, int n2){
    if(n1<root->data && n2<root->data){
       return LCA(root->left,n1,n2);
    }
    else if(n1>root->data && n2>root->data){
        return LCA(root->right,n1,n2);
    }
    else{
        return root;
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
        cout<<LCA(root,2,3)->data<<endl;
    }
    return 0;
}
