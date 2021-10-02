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
bool isPalindrome(ListNode* head) {
    ListNode* s=head;
    ListNode* f=head->next;
    while(f && f->next){
        s=s->next;
        f=f->next->next;
    }
    ListNode* p=nullptr;
    ListNode* c=s->next;
    while(c){
        ListNode* t=c->next;
        c->next=p;
        p=c;
        c=t;
    }
    s->next=p;
    s=s->next;
    while(s){
        if(head->val!=s->val){
            return false;
        }
        s=s->next;
        head=head->next;
    }
    return true;
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
        cout<<isPalindrome(head1);
        
    }
    return 0;
}
