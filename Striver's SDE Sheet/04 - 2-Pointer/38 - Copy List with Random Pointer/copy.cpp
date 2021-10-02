#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod=1e9+7;
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode* random;
    ListNode(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
void print(ListNode* head){
    struct ListNode* temp = head;
    while(temp!=nullptr){
        cout<<temp->val<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}
ListNode* pushnode(int data,ListNode* head){
    ListNode* temp = new ListNode(data);
    temp->next=head;
    head=temp;
    return head;
}
ListNode* copyRandomList(ListNode* head) {
    ListNode* it=head;
    ListNode* f=head;
    while(it){
        f=it->next;
        ListNode* n=new ListNode(it->val);
        it->next=n;
        n->next=f;
        it=f;
    }
    it=head;
    while(it){
        if(it->random){
            it->next->random=it->random->next;
        }
        else{
            it->next->random=NULL;
        }
        it=it->next->next;
    }
    it=head;
    ListNode* r=new ListNode(0);
    ListNode* t=r;
    while(it){
        f=it->next->next;
        t->next=it->next;
        it->next=f;
        t=t->next;
        it=it->next;
    }
    return r->next;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        ListNode* head1=nullptr;
        head1=pushnode(1,head1);
        head1=pushnode(2,head1);
        head1=pushnode(3,head1);
        head1=pushnode(3,head1);
        head1=pushnode(2,head1);
        head1=pushnode(1,head1);
        print(head1);
        print(copyRandomList(head1));
    }
    return 0;
}
