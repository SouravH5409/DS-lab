#include<stdio.h>
#define MAX 100
int cqueue[MAX];
int front = -1,rear = -1;
void Enqueue(int data){
	if((rear+1)%MAX==front){
		printf("Queue is full\n");
  }
  	else{
  	 
  		if(front ==-1){
		front =0;
		rear= 0;
		cqueue[rear]=data;
	}
		else{
		rear=(rear+1)%MAX;
		cqueue[rear]=data;
	}
}
}
void Dequeue(){
	if (front==-1){
		printf("Queue is empty\n");
		}
	else if(front == rear){
		int item=cqueue[front];
		printf("Dequeued Element is:%d\n",item);
		front=(front+1)%MAX;
	}
	else{
		front=(front+1)%MAX;
	}
}
void Display(){
	if(front==-1 && rear==-1){
		printf("Queue empty\n");
	}
	else{
		if(front<=rear)
		{
		for(int i=front;i<=rear;i++){
			printf("%d\t",cqueue[i]);
			printf("\n");
		}
	   }
		else{ 
		
	   	for(int i=0;i<MAX;i++){
		printf("%d",cqueue[i]);
	  }
	  }
}
}
void main(){
	int ch;
	do{
	printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
	printf("Enter your choice");
	
	scanf("%d",&ch);
	switch(ch){
	
		case 1:
			int item;
			printf("Enter item\n");
			scanf("%d",&item);
			Enqueue(item);
			break;
		case 2:
			Dequeue();
			break;
		case 3:
			Display();
			break;
		case 4:
			break;
		
	}
}
	while(ch<4);
}
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
	  
