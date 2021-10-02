#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct Stack{
    int top;
    unsigned capacity;
    int* array;
};
void push(struct Stack* stack, int item){
    stack->array[++stack->top]=item;
}
int pop(struct Stack* stack){
    if(stack->top==-1){
        return -1;
    }
    return stack->array[stack->top--];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T=1;
    //cin>>T;
    while(T--){
        Stack *st;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            push(st,x);
        }
        for(int i=0;i<n;i++){
            cout<<st->array[i]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
