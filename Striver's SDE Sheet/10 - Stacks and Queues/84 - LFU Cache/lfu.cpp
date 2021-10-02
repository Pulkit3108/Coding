#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct Node{
    int key;
    int value;
    int c;
    Node *next; 
    Node *prev;
    Node(int k,int v){
        key=k;
        value=v; 
        c=1; 
    }
}; 
struct List{
    int size; 
    Node *head; 
    Node *tail; 
    List(){
        head=new Node(0,0); 
        tail=new Node(0,0); 
        head->next=tail;
        tail->prev=head;
        head->prev=nullptr;
        tail->next=nullptr; 
        size=0;
    }
    void addNode(Node *n){
        Node* t=head->next;
        n->next=t;
        n->prev=head;
        head->next=n;
        t->prev=n;
        size+=1; 
    }
    void delNode(Node* d){
        Node* pr=d->prev;
        Node* ne=d->next;
        pr->next=ne;
        ne->prev=pr;
        size-=1; 
    } 
};
class LFUCache{
    map<int,Node*> mp_k; 
    map<int,List*> mp_f; 
    int capacity;
    int mf; 
    int cs; 
public:
    LFUCache(int capacity) {
        this->capacity=capacity; 
        mf=0;
        cs=0; 
    }
    void updateFreqListMap(Node *n){
        mp_k.erase(n->key); 
        mp_f[n->c]->delNode(n); 
        if(n->c==mf && mp_f[n->c]->size==0){
            mf+=1; 
        }
        List* h=new List();
        if(mp_f.find(n->c+1)!=mp_f.end()){
            h=mp_f[n->c+1];
        } 
        n->c+=1; 
        h->addNode(n); 
        mp_f[n->c]=h; 
        mp_k[n->key]=n;
    }
    int get(int key) {
        if(mp_k.find(key)!=mp_k.end()){
            Node* t=mp_k[key]; 
            int v=t->value; 
            updateFreqListMap(t); 
            return v; 
        }
        return -1; 
    }
    void put(int key, int value){
        if(capacity==0){
            return;
        }
        if(mp_k.find(key)!=mp_k.end()){
            Node* t=mp_k[key]; 
            t->value=value; 
            updateFreqListMap(t); 
        }
        else{
            if(cs==capacity){
                List* l=mp_f[mf]; 
                mp_k.erase(l->tail->prev->key); 
                mp_f[mf]->delNode(l->tail->prev);
                cs-=1; 
            }
            cs+=1; 
            mf=1; 
            List* l=new List(); 
            if(mp_f.find(mf)!=mp_f.end()){
                l=mp_f[mf]; 
            }
            Node* n=new Node(key, value); 
            l->addNode(n);
            mp_k[key]=n; 
            mp_f[mf]=l; 
        }
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
        LFUCache* obj = new LFUCache(n);
        obj->put(1,1);
        obj->put(2,2);
        cout<<obj->get(1)<<endl;
        cout<<obj->get(2)<<endl;
        obj->put(3,3);
        cout<<obj->get(2)<<endl;
        cout<<obj->get(3)<<endl;
        obj->put(4,4);
        cout<<obj->get(1)<<endl;
        cout<<obj->get(3)<<endl;
        cout<<obj->get(4)<<endl;
    }
    return 0;
}
