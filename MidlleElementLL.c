#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* head=NULL;
void insert(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    if(head==NULL){
        newNode->next=NULL;
        head=newNode;
    }
    else{
        struct Node* temp=head;
        while(temp->next!=NULL){
                temp=temp->next;
        }
        newNode->next=NULL;
        temp->next=newNode;
    }
}

int findMiddle(struct Node* head){
    struct Node* flag1=head;
    struct Node* flag2=head;
    while(flag2!=NULL && flag2->next!=NULL){
        flag1=flag1->next;
        flag2=flag2->next->next;
    }
    return flag1->data;
}

void main(){
    insert(1);
    insert(3);
    insert(4);
    insert(2);
    insert(5);
    insert(7);

    printf("%d",findMiddle(head));
}
