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
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(!l1){
        return l2;
    }
    if(!l2){
        return l1;
    }
    if(l1->val>l2->val){
        ListNode* t=l1;
        l1=l2;
        l2=t;
    }
    ListNode* r=l1;
    while(l1 && l2){
        ListNode* t=nullptr;
        while(l1 && l1->val<=l2->val){
            t=l1;
            l1=l1->next;
        }
        t->next=l2;
        ListNode* s=l1;
        l1=l2;
        l2=s;
    }
    return r;
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
        ListNode* head2=nullptr;
        head2=pushnode(11,head2);
        head2=pushnode(10,head2);
        head2=pushnode(9,head2);
        print(head2);
        print(mergeTwoLists(head1,head2));
    }
    return 0;
}
