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
void leftrecur(Node* root,int l,vector<int> &t){
    if(!root){
        return;
    }
    if(l==t.size()){
        t.push_back(root->data);
    }
    leftrecur(root->left,l+1,t);
    leftrecur(root->right,l+1,t);
}
vector<int> leftView(Node *root){
   vector<int> lf;
   leftrecur(root,0,lf);
   return lf;
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
        vector<int> a=leftView(root);
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
