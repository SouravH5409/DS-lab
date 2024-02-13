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
    newNode->next=NULL;
    
    if(head==NULL){
        head=newNode;
    }
    else{
        struct Node* ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=newNode;
    }
}

void display(){
    struct Node* temp=head;
    if(head==NULL){
        printf("list empty");
    }
    else{
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
void sortLL(){
    struct Node *current;
    struct Node *nextNode;
    int temp;
    if (head == NULL)
        return;
    int swapped;
    do {
        swapped = 0;
        current = head;
        while (current->next != NULL) {
            nextNode = current->next;
            if (current->data > nextNode->data) {
                temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}


void findDuplicate(){
    struct Node* current=head;
    struct Node* next_next;
    sortLL();
    while(current != NULL && current->next != NULL){
        if(current->data == current->next->data){
            next_next=current->next->next;
            free(current->next);
            current->next=next_next;
        }
        else{
            current=current->next;
        }
    }
}

void main(){
    insert(2);
    insert(4);
    insert(6);
    insert(1);
    insert(5);
    insert(5);
    insert(2);
    
    printf("Original List: ");
    display();
    
    findDuplicate();
    
    printf("List after removing duplicates: ");
    display();
}
