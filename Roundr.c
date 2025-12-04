#include<stdio.h>
struct PIB{
int pid,burst,rem,tat,waiting;
};
int main(){
struct PIB p[10],temp;
int num,ts,time=0,complete=0;
printf("Enter no of processes:");
scanf("%d",&num);
for(int i=0;i<num;i++){
p[i].pid=i+1;
printf("Enter burst of %d:",i+1);
scanf("%d",&p[i].burst);
p[i].rem = p[i].burst;
}
printf("Enter timeslice:");
scanf("%d",&ts);
printf("\t\t\t\t\t\t\tGANT CHART\n");
for(int i=0;i<num*40;i++){
printf("_");
}
printf("\n");
while(num>complete){
for(int i=0;i<num;i++){
if(p[i].rem !=0){
printf("\t%d\t",p[i].pid);
if(p[i].rem >ts){
time +=ts;
p[i].rem -= ts;
}
else{
time += p[i].rem;
p[i].tat=time;
p[i].waiting = time - p[i].burst;
p[i].rem =0;
complete++;
}
}
}
}
printf("\n");
for(int i=0;i<num*40;i++){
printf("_");
}
printf("\n");
printf("0");
time=0,complete=0;
for(int i=0;i<num;i++){
p[i].rem=p[i].burst;
}
while(num>complete){
for(int i=0;i<num;i++){
if(p[i].rem !=0){
if(p[i].rem >ts){
time +=ts;
p[i].rem -= ts;
printf("\t\t%d",time);
} 
else{
time += p[i].rem;
p[i].rem =0;
printf("\t\t%d",time);
complete++;
}
}
}
}
printf("\n\n\n");
printf("PID\tBT\tWT\tTAT\n");
for(int i=0;i<num;i++){
printf("%d\t%d\t%d\t%d\t\n",p[i].pid,p[i].burst,p[i].waiting,p[i].tat);
}
float atat=0,awt=0;
for(int i=0;i<num;i++){
awt += p[i].waiting;
atat +=p[i].tat;
}
awt=awt/(float)num;
atat=atat/(float)num;
printf("Average Waiting Time:%.2f\n",awt);
printf("Average Turnaround Time:%.2f\n",atat);
}