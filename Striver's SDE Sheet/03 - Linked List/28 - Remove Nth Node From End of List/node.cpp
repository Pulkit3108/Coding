#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mod=1e9+7;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void print(ListNode* head){
    struct ListNode* temp = head;
    while(temp!=nullptr){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<endl;
}
ListNode* pushnode(int data,ListNode* head){
    ListNode* temp = new ListNode(data);
    temp->next=head;
    head=temp;
    return head;
}
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* t=new ListNode();
    t->next=head;
    ListNode* f=t;
    ListNode* s=t;
    while(n--){
        f=f->next;
    }
    while(f->next){
        f=f->next;
        s=s->next;
    }
    ListNode* d=s->next;
    s->next=s->next->next;
    delete(d);
    return t->next;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        ListNode* head1=nullptr;
        head1=pushnode(8,head1);
        head1=pushnode(7,head1);
        head1=pushnode(6,head1);
        head1=pushnode(5,head1);
        print(head1);
        print(removeNthFromEnd(head1,2));
    }
    return 0;
}
