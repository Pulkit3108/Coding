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
struct info{
    int s;
    int mx;
    int mn;
    bool bst;
    int r;
};
info helper(Node* root){
    if(!root){
        return {0,INT_MIN,INT_MAX,true,0};
    }
    info l=helper(root->left);
    info r=helper(root->right);
    info t;
    t.s=1+l.s+r.s;
    if(l.bst && r.bst && l.mx<root->data && r.mn>root->data){
        t.mn=min(l.mn,min(r.mn,root->data));
        t.mx=max(l.mx,max(r.mx,root->data));
        t.r=t.s;
        t.bst=true;
    }
    else{
        t.r=max(l.r,r.r);
        t.bst=false;
    }
    return t;
}
int largestBst(Node *root){
    return helper(root).r;
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
        cout<<largestBst(root);
    }
    return 0;
}
