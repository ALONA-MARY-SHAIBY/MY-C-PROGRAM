#include<stdio.h>
 int main(){
 int i,n,x,flag=0,mid,space=0,t=0;
 t++;
  printf("Enter the limit:");
   scanf("%d",&n);
   t++;
int lft=0,rht=n-1;
t++;
int a[n];
t++;
printf("Enter the array elements:");
for(i=0;i<n;i++,t++){
scanf("%d",&a[i]);
t++;
}
printf("Enter the element:");
 scanf("%d",&x); 
 t++;
while(lft<=rht){
mid=(lft+rht)/2;
t++;
t++;
if(x==a[mid]){
flag=1;
t++;
t++;
break;
}
else if(x>a[mid]){
lft=mid+1;
t++;
t++;
}
else if(x<a[mid]){
rht=mid-1;
t++;
t++;
}
}
if(flag==0){
printf("Element not found");
t++;
}
else if(flag==1){
printf("Element found\n");
t++;
} 

space=40+(4*n);
t++;
t++;
t++;
t++;
printf("space complexity of the program: %d", space);
printf("\nThe time complexity of the program: %d", t);
return 0;
}