#include<stdio.h>
int top=-1,stack[20];
void push(int size,int item){
if(top>=size-1){
printf("Stack Overflow");
}
else{
top++;
stack[top]=item;
printf("%d is inserted into the stack\n",item);
}
}
void pop(){
if(top==-1){
printf("\nStack underflow");
}
else{
int item;
item=stack[top];
top=top-1;
printf("%d is deleted from the stack\n",item);
}
}
void display(){
if(top==-1){
printf("The stack is empty\n");
}
else{
printf("The stack is:\n");
for(int i=top;i>=0;i--){
printf("%d\n",stack[i]);
}
}
}
int main(){
int choice,item,size;
printf("Enter size of stack: ");
scanf("%d",&size);
while(1){
printf("\nSelect your choice: ");
printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
scanf("%d",&choice);
switch(choice){
case 1:printf("\nEnter element to be inserted: ");
scanf("%d",&item);
push(size,item);
break;
case 2:
pop();
break;
case 3:
display();
break;
case 4:
printf("Exiting...");
return 0;
break;
default:printf("Invalid choice");
break;
}
}
return 0;
}