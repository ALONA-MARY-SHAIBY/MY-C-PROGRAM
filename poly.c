#include<stdio.h>
struct poly{
    int coeff;
    int exp;
    /* data */
};
int main(){
    int n;
    printf("Enter the size:");
    scanf("%d",&n);
    struct poly x[n];
    for(int i=0;i<n;i++){
        printf("Enter the coeff:");
        scanf("%d",&x[i].coeff);
        printf("Enter the exp:");
        scanf("%d",&x[i].exp);
        
    }
    printf("The plynomial is:");
     for(int i=0;i<n;i++){
        printf("%dx^%d",x[i].coeff,x[i].exp);
        if(i<n-1){
            printf("+");
        }
     }
     printf("\n");
     return 0;
}
