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
ListNode* middleNode(ListNode* head){
    ListNode* s=head;
    ListNode* f=head;
    while(f && f->next){
        s=s->next;
        f=f->next->next;
    }
    return s;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T=1;
    //cin>>T;
    while(T--){
        ListNode* head=nullptr;
        head=pushnode(5,head);
        head=pushnode(6,head);
        head=pushnode(7,head);
        head=pushnode(8,head);
        print(head);
        cout<<middleNode(head)->val;
    }
    return 0;
}
