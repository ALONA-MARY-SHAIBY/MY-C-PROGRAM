#include<stdio.h>
int main(){
int i,n,x,count=0,space,t=0;
t++;
printf("Enter the limit:");
scanf("%d",&n);
    t++;
    int a[n];
    t++;
    printf("Enter the elements:");
    for(i=0;i<n;i++,t++){
        scanf("%d",&a[i]);
        t++;
    }
    printf("Enter the element:");
    scanf("%d",&x);
    t++;
    for(i=0;i<n;i++,t++){
        if(a[i]==x){
            count++;
            t++;
            printf("Element found at position:%d",i+1);
            t++;
        }
    }
    if(count == 0){
        t++;
        printf("\nItem not found");
        t++;
    }
    else{
        printf("\nItem found %d times",count);
        t++;
    }
    space=24+(4*n);
    t++;
    t++;
    t++;
    t++;
    printf("\nSpace complexity is:%d",space);
    printf("\nTime complexity is:%d",t);
    return 0 ;
}