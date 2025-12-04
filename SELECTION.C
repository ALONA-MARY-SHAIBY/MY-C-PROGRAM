#include<stdio.h>
int main(){
int n,t=1;
int arr[30];
printf("Enter the no of elements:");
t++;
scanf("%d",&n);
t++;
printf("Enter the elements:");
t++;
for(int i=0;i<n;i++,t++){
  scanf("%d",&arr[i]);
}
int i=0;
while(i<n-1){
   t++;
   int s=i;
   int j=i+1;
   while(j<n){
    t++;
          if(arr[j]<arr[s]){
             s=j;
          }
   j++;
   }
if(i!=s){
    int temp=arr[s];
    arr[s]=arr[i];
    arr[i]=temp;
}
i++;
}
printf("\nSorted array is:");
t++;
for(i=0;i<n;i++,t++){
  printf("\t%d",arr[i]);
} 
printf("Space Complexity:%d",20+n*4);
printf("Time Complexity:%d",t);
return 0;
}

