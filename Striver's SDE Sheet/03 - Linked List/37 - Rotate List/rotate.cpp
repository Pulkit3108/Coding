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
ListNode* rotateRight(ListNode* head, int k) {
    if(!head || !head->next || k==0){
        return head;
    }
    int cnt=1;
    ListNode* t=head;
    while(t->next){
        t=t->next;
        cnt+=1;
    }
    t->next=head;
    k%=cnt;
    k=cnt-k;
    while(k--){
        t=t->next;
    }
    head=t->next;
    t->next=nullptr;
    return head;
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
        print(rotateRight(head1,3));
    }
    return 0;
}
