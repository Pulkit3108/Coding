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
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* t1=headA;
    ListNode* t2=headB;
    while(t1!=t2){
        t1=t1 ? t1->next:headB;
        t2=t2 ? t2->next:headA;
    }
    return t1;
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
        print(head1);
        ListNode* head2=nullptr;
        head2=pushnode(5,head2);
        head2=pushnode(6,head2);
        head2=pushnode(7,head2);
        print(head2);
        ListNode* t=head2;
        while(t->next){
            t=t->next;
        }
        t->next=head1->next->next;
        print(getIntersectionNode(head1,head2));
    }
    return 0;
}
