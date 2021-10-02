#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct Node{
    int data;
    Node* left;
    Node* right;
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
    return root;
}
void display(Node* root){
    if(root!=NULL){
        cout<<root->data <<" ";
        display(root->left);
        display(root->right);
    }
}
int diameter(Node* root, int& res){
    if(root==NULL){
        return 0;
    }
    int l=diameter(root->left,res);
    int r=diameter(root->right,res);
    int t=1+max(l,r);
    res=max(res,1+l+r);
    return t;
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
        diameter(root,res);
        cout<<res<<endl;
    }
    return 0;
}
