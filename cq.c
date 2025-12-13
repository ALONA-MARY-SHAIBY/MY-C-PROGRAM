#include<stdio.h>
int front=-1,rear=-1;
int CQueue[20];
void enqueue(int item,int size){
if (front==(rear+1)%size){
printf("CircularQueue Overflow");
}
else{
if(front==-1){
front=0;
}
rear=(rear+1)%size;
CQueue[rear]=item;
printf("Element inserted");
}
}
void dequeue(int size){
if(front==-1&&rear==-1){
printf("CircularQueue Underflow");
}
else if (front==rear){
int item=CQueue[front];
front=-1,rear=-1;
printf("Element deleted is:%d",item);
}
else{
int item= CQueue[front];
front=(front+1)%size;
printf("Deleted element is:%d",item);
}
}
void Display(int item,int size,int Queue[]){
if(front==-1){
printf("Circular Queue is empty");
}
else{
printf("The Queue is\n");
int i=front;
while(1){
printf("%d\t",CQueue[i]);
if(i==rear){
break;
}
i=(i+1)%size;
}
}
}
int main(){
int size;
printf("Enter the size:");
scanf("%d",&size);
int CQueue[size];
int choice,item;
while(1){
printf("\nEnter your choice:");
printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT");
scanf("%d",&choice);
switch(choice){
case 1:
printf("Enter the element:");
scanf("%d",&item);
enqueue(item,size);
break;
case 2:
dequeue(size);
break;
case 3:
Display(item,size,CQueue);
break;
case 4:
return 0;
default:
break;
}
}
return 0;
}