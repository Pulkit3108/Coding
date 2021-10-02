#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class Node{
public:
    int key;
    int value;
    Node* next=nullptr;
    Node* prev=nullptr;
    Node(int a,int b){
        key=a;
        value=b;
    }
};
class LRUCache {
    Node* head=new Node(0,0);
    Node* tail=new Node(0,0);
    unordered_map<int,Node*> mp;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void addNode(Node* n){
        Node* t=head->next;
        head->next=n;
        n->prev=head;
        n->next=t;
        t->prev=n;
    }
    void delNode(Node* n){
        Node* p=n->prev;
        Node* ne=n->next;
        p->next=ne;
        ne->prev=p;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* t=mp[key];
            int r=t->value;
            mp.erase(key);
            delNode(t);
            addNode(t);
            mp[key]=head->next;
            return r;
        }
        return -1;
    }
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* t=mp[key];
            mp.erase(key);
            delNode(t);
        }       
        if(mp.size()==capacity){
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }
        Node* n=new Node(key,value);
        addNode(n);
        mp[key]=n;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        LRUCache* obj = new LRUCache(n);
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            obj->put(x,y);
        }
        int t;
        cin>>t;
        int param_1 = obj->get(t);
        cout<<t<<endl;
    }
    return 0;
}
