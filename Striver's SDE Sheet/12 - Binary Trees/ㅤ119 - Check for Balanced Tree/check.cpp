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
int getdepth(Node* root){
    if(!root){
        return 0;
    }
    int l=getdepth(root->left);
    int r=getdepth(root->right);
    if(l==-1 || r==-1){
        return -1;
    }
    if(abs(l-r)>1){
        return -1;
    }
    return 1+max(l,r);
}
bool isBalanced(Node *root){
    if(getdepth(root)<0){
        return false;
    }
    else{
        return true;
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
        cout<<isBalanced(root)<<endl;
    }
    return 0;
}
