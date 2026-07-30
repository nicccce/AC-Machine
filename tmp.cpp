#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
struct node
{
    int v;
    node* next=nullptr;
};

void swap(node* pre){
    node* k=pre->next;
    node* next=k->next;
    if(k->v<next->v){
        return;
    }
    k->next=next->next;
    pre->next=next;
    next->next=k;
}
node* sort(node *head){
    node tmp{0,head};
    node* now=head;
    int n=0;
    while(now!=nullptr){
        now=now->next;
        n++;
    }
    for(int j=0;j<n-1;j++){
        now=&tmp;
        for(int i=0;i<n-1;i++){
            swap(now);
            now=now->next;
        }
    }
    return tmp.next;
}
int main() {
    node head{2},k1{3},k2{1};
    head.next=&k1;
    k1.next=&k2;
    node* now= sort(&head);
    while(now!=nullptr){
        cout<<now->v<<endl;
        now=now->next;
    }
    return 0;
}