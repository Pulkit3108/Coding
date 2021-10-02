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
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* t=head;
    int cnt=0;
    while(t){
        cnt+=1;
        t=t->next;
    }
    ListNode* r=new ListNode();
    r->next=head;
    ListNode* p=r;
    ListNode* c=r;
    t=r;
    while(cnt>=k){
        c=p->next;
        t=c->next;
        for(int i=1;i<k;i++){
            c->next=t->next;
            t->next=p->next;
            p->next=t;
            t=c->next;
        }
        p=c;
        cnt-=k;
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
        head1=pushnode(4,head1);
        head1=pushnode(5,head1);
        head1=pushnode(6,head1);
        print(head1);
        print(reverseKGroup(head1,3));
        
    }
    return 0;
}
