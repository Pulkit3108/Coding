#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        n->next = head;
        head = n;
    }
}
void display(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
bool search(node *&head, int val)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void reverse(node *&head)
{
    node *prev = NULL;
    node *curr = head;
    while (curr != NULL)
    {
        node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll T = 1;
    // cin>>T;
    while (T--)
    {
        node *head = NULL;
        insertAtTail(head, 1);
        insertAtTail(head, 2);
        insertAtTail(head, 3);
        display(head);
        insertAtHead(head, 4);
        insertAtHead(head, 5);
        display(head);
        reverse(head);
        display(head);
        cout << search(head, 5) << endl;
    }
    return 0;
}