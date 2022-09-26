// ANSWER 1

#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

void append(Node*&head,int data){
    Node*temp=head;
    Node*newnode=new Node(data);
    if(temp==NULL){
    head=newnode;
    newnode->next=head;
    return;
    }
    while(temp->next!=head){
        temp=temp->next;
        }   
    //CONDITION
/* The condition says that we save the actual head of the LL and then can easily transverse the whole LL to find where we have finally reached
the start of the LL
*/
    temp->next=newnode;
    newnode->next=head;
}

void display(Node*&head){
    Node*temp=head;
    do{
        cout<<temp->data<<"->";
        temp=temp->next;
        }
    while(temp!=head);
}

int main(){
    Node*head=NULL;
    append(head,0);
    append(head,1);
    append(head,2);
    display(head);
}




/*ANSWER 2:-  
PRACTICAL APPLICATIONS OF CIRCULAR LINKED LIST:
-It is used by the Operating system to share time for different users, generally uses a Round-Robin time-sharing mechanism.
-Multiplayer games use a circular list to swap between players in a loop.
-Used in places where data structures have real-life application for example in a music player playlist.
-Implementation of Advanced data structures like Fibonacci Heap
-The browser cache which allows you to hit the BACK button
-Undo functionality in Photoshop or Word
-Circular linked list used Most recent list (MRU LIST)
*/
