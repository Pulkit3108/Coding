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
void deleteNode(ListNode* node) {
    node->val=node->next->val;
    ListNode* t=node->next;
    node->next=node->next->next;
    delete(t);
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
        ListNode* t=head1;
        head1=pushnode(6,head1);
        head1=pushnode(5,head1);
        print(head1);
        deleteNode(t);
        print(head1);
    }
    return 0;
}
