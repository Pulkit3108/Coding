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
bool hasCycle(ListNode *head) {
    ListNode* s=head;
    ListNode* f=head;
    while(f && f->next){
        s=s->next;
        f=f->next->next;
        if(s==f){
            return true;
        }
    }
    return false;
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
        ListNode* t=head1;
        head1=pushnode(2,head1);
        head1=pushnode(3,head1);
        head1=pushnode(4,head1);
        t->next=head1->next;
        cout<<hasCycle(head1);
    }
    return 0;
}
