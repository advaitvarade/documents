#include<stdio.h>
#include<stdlib.h>
struct Process{
    int pid;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnAroundTime;
};
void fcfs(struct Process p[], int n){
    p[0].completionTime=p[0].burstTime;
    for(int i=1;i<n;i++){
        p[i].completionTime=p[i-1].completionTime+p[i].burstTime;
    }
    for(int i=0;i<n;i++){
        p[i].turnAroundTime=p[i].completionTime-p[i].arrivalTime;
    }
    p[0].waitingTime=0;
    for(int i=1;i<n;i++){
        p[i].waitingTime=p[i].turnAroundTime-p[i].burstTime;
    }

}
void findSJFP(struct Process p[],int n){
    int remainingTime[n];
    for(int i=0;i<n;i++){
        remainingTime[i]=p[i].burstTime;
    }
    int currentTime=0;
    int minBurst=9999;
    int shortest=-1;
    int completed=0;
    while(completed<n){
        minBurst=9999;
        shortest=-1;
        for(int i=0;i<n;i++){
            if(p[i].arrivalTime<=currentTime && remainingTime[i] < minBurst && remainingTime[i] > 0){
                minBurst=remainingTime[i];
                shortest=i;
            }
        }
        if(shortest==-1){
            currentTime++;
            continue;
        }
        remainingTime[shortest]--;
        if(remainingTime[shortest]==0){
            completed++;
            p[shortest].completionTime=currentTime+1;
            p[shortest].turnAroundTime=p[shortest].completionTime-p[shortest].arrivalTime;
            p[shortest].waitingTime=p[shortest].turnAroundTime-p[shortest].burstTime;
        }
        currentTime++;
    }
}
void findSJFnP(struct Process p[], int n){
    int remainingTime[n];
    for (int  i = 0; i < n; i++){
        remainingTime[i]=p[i].burstTime;
    }
    
    int completed=0;
    int shortest=-1;
    int minBurst=9999;
    int currentTime=0;
    while(completed<n){
        minBurst=999;
        shortest=-1;
        for(int i=0;i<n;i++){
            if(p[i].arrivalTime<=currentTime && remainingTime[i]<minBurst && remainingTime[i]!=0){
                minBurst=remainingTime[i];
                shortest=i;
            }
            
        }
        if(shortest==-1){
            currentTime++;
            continue;
        }

        remainingTime[shortest]=0;
        currentTime=currentTime+p[shortest].burstTime;
        completed++;
        p[shortest].completionTime=currentTime;
        p[shortest].turnAroundTime=p[shortest].completionTime-p[shortest].arrivalTime;
        p[shortest].waitingTime=p[shortest].turnAroundTime-p[shortest].burstTime;
        
    }
}
void RoundRobin(struct Process p[], int n,int quantum){
    int remainingTime[n];
    for(int i=0;i<n;i++){
        remainingTime[i]=p[i].burstTime;
    }
    int completed=0;
    int currentTime=0;
    while(completed<n){
        for(int i=0;i<n;i++){
            if(remainingTime[i] > 0){
                if(remainingTime[i] > quantum){
                    currentTime=currentTime+quantum;
                    remainingTime[i]=remainingTime[i]-quantum;
                }
                else{
                    currentTime=currentTime+remainingTime[i];
                    remainingTime[i]=0;
                    p[i].completionTime=currentTime;
                    completed++;
                }
            }
        }
    }
}
int main(){
    int n=4;
    struct Process p[]={{1,0,7},{2,2,4},{3,4,1},{4,5,4}};
    //findSJF(p,n);
    //findSJFnP(p,n);
    RoundRobin(p,n,2);
    fcfs(p,n);
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrivalTime,
               p[i].burstTime,
               p[i].completionTime,
               p[i].turnAroundTime,
               p[i].waitingTime);
    }

}