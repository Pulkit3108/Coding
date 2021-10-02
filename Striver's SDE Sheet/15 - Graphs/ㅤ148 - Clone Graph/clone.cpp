#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
Node* dfs(Node* node,unordered_map<Node*,Node*> &mp){
    if(!node){
        return node;
    }
    if(mp.find(node)!=mp.end()){ 
        return mp[node];
    }
    else{
        Node* c=new Node(node->val);
        mp[node]=c;
        for(auto &it:node->neighbors){
            c->neighbors.push_back(dfs(it,mp));
        }
        return c;
    }
}    
Node* cloneGraph(Node* node){
    unordered_map<Node*,Node*> mp;
    return dfs(node,mp);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){

    }
    return 0;
}
