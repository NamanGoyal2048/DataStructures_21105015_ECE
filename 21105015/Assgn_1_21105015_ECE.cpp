#include <iostream>
using namespace std;


class Family{
    public:
    string name;
    int age;
    Family*next;
    Family*prev;
    Family(string name,int age){

        this->age=age;
        this->name=name;
        next=NULL;
        prev=NULL;
    }
};


void append(Family* &head,string name,int age){
    Family*temp=head;
    Family*new_node=new Family(name,age);
    if(temp==NULL){
        head=new_node;
    }
    else{
        while(temp->next!=NULL){temp=temp->next;}
        temp->next=new_node;
        new_node->prev=temp;
    }
}


void insert_at_head(Family*&head,string name,int age){
     Family*new_node=new Family(name,age);
     new_node->next=head;
     head->prev=new_node;
     head=new_node;
}


void peek(Family*head){
    Family*temp=head;
    while(temp!=NULL){
    cout<<"Name:"<<temp->name<<endl;
    cout<<" Age:"<<temp->age<<endl;;
    temp=temp->next;}
    cout<<endl;
}


void display_end(Family*head){
    Family*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    while(temp!=NULL){
    cout<<"Name:"<<temp->name<<endl;
    cout<<" Age:"<<temp->age<<endl;
    temp=temp->prev;}
    cout<<endl;
}

void delete_at_i(Family*&head,int i){
    if(i==0){
        Family*temp=head;
        head=temp->next;
        head->prev=NULL;
        delete temp;
    }
    else{
        Family*temp=head;
        for(int j=0;j<i;j++){
        temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
}

void pop(Family*&head){
    Family*temp=head;
    while(temp->next!=NULL){temp=temp->next;}
    temp->prev->next=NULL;
    delete temp;
}

int main(){
    Family*head=NULL;
    append(head,"MEMBER A",80);
    append(head,"MEMBER B",50);
    append(head,"MEMBER C",47);
    append(head,"MEMBER D",22);
    append(head,"MEMBER E",19);
    cout<<endl;

    cout<<"Doubly Linked list with family members without age sorting:"<<endl;
    cout<<endl;
    peek(head);
    display_end(head);
    delete_at_i(head,3);
    cout<<"Doubly Linked List after the changes made:"<<endl;
    peek(head);
}


/*The LL can be used to link the family members doubly-linked list based on their relationship if the list is being sorted in decreasing order on the basis 
of the age of the member every time a new member  is added to the list because then when the senior most person for example the grandfather will be added
to the list he will be at the beginning of the list and his son/daughter then accordingly will come after him.*/
