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
vector<int> topView(Node *root) {
    vector<int> tv;
    queue<pair<Node*,int>> q;
    map<int,Node*> mp;
    q.push({root,0});
    while(!q.empty()){
        int l=q.front().second;
        Node* t=q.front().first;
        if(mp.find(l)==mp.end()){
            mp[l]=t;
        }
        q.pop();
        if(t->left){
            q.push({t->left,l-1});
        }
        if(t->right){
            q.push({t->right,l+1});
        }
    }
    for(auto &it:mp){
        tv.push_back(it.second->data);
    }
    return tv;
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
        vector<int> a=topView(root);
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
