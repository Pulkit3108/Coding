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
int findCeil(Node *node, int x){
    int c=-1;
    while(node){
        if(node->data==x){
            return x;
        }
        else if(node->data>x){
            c=node->data;
            node=node->left;
        }
        else{
            node=node->right;
        }
    }
    return c;
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
        cout<<findCeil(root,5);
    }
    return 0;
}
