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
bool isIdentical(Node *r1, Node *r2){
    if(!r1 && !r2){
        return true;
    }
    if(!r1 || !r2 || r1->data!=r2->data){
        return false;
    }
    return isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
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
        cout<<isIdentical(root,root->left)<<endl;
    }
    return 0;
}
