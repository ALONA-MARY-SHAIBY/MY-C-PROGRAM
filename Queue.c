#include<stdio.h>
int front=-1,rear=-1;
void enqueue(int item,int size,int Queue[]){
if (rear==size-1){
printf("Queue Overflow");
}
else{
if(front==-1){
front=0;
}
rear=rear+1;
Queue[rear]=item;
printf("Element inserted");
}
}
void dequeue(int item, int size,int Queue[]){
if(rear<front||front==-1){

printf("Queue Underflow");
}
else{
int item;
item=Queue[front];
front++;
printf("Element deleted is:%d",item);
}
}
void Display(int item,int size,int Queue[]){
if(front==rear==-1){
printf("Queue is empty");
}
else{
printf("The Queue is\n");
for(int i=front;i<=rear;i++){
printf("%d\t",Queue[i]);
}
}
}
int main(){
int size;
printf("Enter the size:");
scanf("%d",&size);
int Queue[size];
int choice,item;
while(1){
printf("\nEnter your choice:");
printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT");
scanf("%d",&choice);
switch(choice){
case 1:
printf("Enter the element:");
scanf("%d",&item);
enqueue(item,size,Queue);
break;
case 2:
dequeue(item,size,Queue);
break;
case 3:
Display(item,size,Queue);
break;
case 4:
return 0;
default:
break;
}
}
return 0;
}