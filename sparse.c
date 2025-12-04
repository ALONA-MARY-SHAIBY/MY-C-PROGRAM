#include<stdio.h>
int main(){
int i,j,row,col;
printf("Enter the no of rows & columns:");
scanf("%d %d", &row, &col);
int A[row][col];
printf("Enter the elements:");
for(i=0;i<row;i++){
    for(j = 0;j<col;j++){
        scanf("%d",&A[i][j]);
}
}
printf("Sparse Matrix is:\n");
for(i=0;i<row;i++){
for(j = 0;j<col;j++){
printf("%d\t",A[i][j]);
}
printf("\n");
}
int count=0,k;
for(i=0;i<row;i++){
for(j = 0;j<col;j++){
if (A[i][j]!=0){
count++;
}
}
}
int B[count+1][3];
k = 1;
B[0][0]=row;
B[0][1]=col;
for(i = 0;i<row;i++){
    for(j=0;j<col;j++){
if (A[i][j]!=0){
B[k][0]=i;
B[k][1]=j;
B[k][2]=A[i][j];
k++;
}
}
}
B[0][2]=k-1;
printf("Row\tColumn\tValue\n");
for(i=0;i<count+1;i++){
for(j=0;j<3;j++){
printf("%d\t",B[i][j]);
}
printf("\n");
}
return 0;
}