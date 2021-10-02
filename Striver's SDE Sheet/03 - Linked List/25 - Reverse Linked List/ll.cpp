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
ListNode* reverseList(ListNode* head){
    ListNode* p=nullptr;
    while(head){
        ListNode* t=head->next;
        head->next=p;
        p=head;
        head=t;
    }
    return p;
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
        print(reverseList(head));
    }
    return 0;
}
