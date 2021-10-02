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
vector<int> bottomView(Node *root) {
    vector<int> bv;
    queue<pair<int,Node*>> q;
    map<int,Node*> mp;
    
    q.push({0,root});
    while(!q.empty()){
        mp[q.front().first]=q.front().second;
        int l=q.front().first;
        Node* t=q.front().second;
        q.pop();
        if(t->left){
            q.push({l-1,t->left});
        }
        if(t->right){
            q.push({l+1,t->right});
        }
    }
    for(auto &it:mp){
        bv.push_back(it.second->data);
    }
    return bv;
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
        vector<int> a=bottomView(root);
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
