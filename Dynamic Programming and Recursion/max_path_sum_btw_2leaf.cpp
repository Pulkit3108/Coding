#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}; 
Node* newNode(int data){
    Node* root=(Node*)malloc(sizeof(Node));
    root->data=data;
    root->left=root->right=NULL;
    return(root);
}
Node* insert(int a[], Node* root, int i, int n){
    if(i<n){
        Node* t=newNode(a[i]);
        root=t;
        root->left=insert(a,root->left,2*i+1,n);
        root->right=insert(a,root->right,2*i+2,n);
    }
    return(root);
}
void display(Node* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        display(root->left);
        display(root->right);
    }
}
int maxPathSum(Node* root, int& res){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return root->data;
    }
    int l=maxPathSum(root->left,res);
    int r=maxPathSum(root->right,res);
    if(root->left!=NULL && root->right!=NULL){
        int t=max(l,r)+root->data;
        res=max(res,l+r+root->data);
        return t;
    }
    if(root->left==NULL){
        return(r+root->data);
    }
    else{
        return(l+root->data);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int a[n];
        int i;
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        int res=INT_MIN;
        Node *root=insert(a,root,0,n);
        maxPathSum(root,res);
        cout<<res<<endl;
    }
    return 0;
}
