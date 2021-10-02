#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class Node{
    public:
        int data;
        Node *next,*bottom;
};
Node* head=NULL;
Node* push(Node* head_ref,int data){
    Node* new_node=new Node();
    new_node->data=data;
    new_node->next=NULL;
    new_node->bottom=head_ref;
    head_ref=new_node;
    return head_ref;
}
void printList(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->bottom;
    }
    cout<<"NULL";
    cout<<endl;
}
Node* merge(Node* l1,Node* l2){
    Node* t=new Node();
    Node* r=t;
    while(l1 && l2){
        if(l1->data<l2->data){
            t->bottom=l1;
            l1=l1->bottom;
        }
        else{
            t->bottom=l2;
            l2=l2->bottom;
        }
        t=t->bottom;
    }
    if(l1){
        t->bottom=l1;
    }
    else{
        t->bottom=l2;
    }
    return r->bottom;
}
Node *flatten(Node *root){
    if(!root || !root->next){
        return root;
    }
    root->next=flatten(root->next);
    root=merge(root,root->next);
    return root;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        head=push(head,30);
        head=push(head,8);
        head=push(head,7);
        head=push(head,5);
        head->next=push(head->next,20);
        head->next=push(head->next,10);
        head->next->next=push(head->next->next,50);
        head->next->next=push(head->next->next,22);
        head->next->next=push(head->next->next,19);
        head->next->next->next=push(head->next->next->next,45);
        head->next->next->next=push(head->next->next->next,40);
        head->next->next->next=push(head->next->next->next,35);
        head->next->next->next=push(head->next->next->next,20);
        head=flatten(head);
        printList();
    }
    return 0;
}
