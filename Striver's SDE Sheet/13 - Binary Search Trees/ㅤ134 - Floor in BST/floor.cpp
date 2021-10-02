#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct Node{
    int val;
    struct Node *left, *right;
    Node(int x){
        val=x;
        left=nullptr;
        right=nullptr;
    }
};
int floorInBST(Node *root, int x){
    int f=root->val;
    while(root){
        if(root->val==x){
            return x;
        }
        else if(x>root->val){
            f=root->val;
            root=root->right;
        }
        else{
            root=root->left;
        }
    }
    return f;
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
        cout<<floorInBST(root,5);
    }
    return 0;
}
