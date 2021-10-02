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
vector<int> findSpiral(Node *root){
    vector<int> lv;
    if(!root){
        return lv;
    }
    bool flag=true;
    deque<Node*> dq;
    Node* t=root;
    dq.push_back(t);
    while(!dq.empty()){
        int s=dq.size();
        for(int i=0;i<s;i++){
            if(flag){
                t=dq.back();
                dq.pop_back();
                if(t->right){
                    dq.push_front(t->right);
                }
                if(t->left){
                    dq.push_front(t->left);
                }
            }
            else{
                t=dq.front();
                dq.pop_front();
                if(t->left){
                    dq.push_back(t->left);
                }
                if(t->right){
                    dq.push_back(t->right);
                }
                
            } 
            lv.push_back(t->data);
        }
        flag=!flag;
    }
    return lv;
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
        vector<int> a=findSpiral(root);
        for(int i=0;i<a.size();i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
