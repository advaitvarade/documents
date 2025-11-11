#include<stdio.h>
int isSafe(int f[], int ans[], int available[], int allocated_matrix[][4],int max_matrix[][4],int need[][4]){
    int ind=0;
    for(int k=0;k<5;k++){
        for(int i=0;i<5;i++){
            if(f[i]==0){
                if( need[i][0]<=available[0] &&
                    need[i][1]<=available[1] &&
                    need[i][2]<=available[2] &&
                    need[i][3]<=available[3]){
                        ans[ind++]=i;
                        available[0]+=allocated_matrix[i][0];
                        available[1]+=allocated_matrix[i][1];
                        available[2]+=allocated_matrix[i][2];
                        available[3]+=allocated_matrix[i][3];
                        f[i]=1;
                }
            }
        }
    }
    for(int i=0;i<5;i++){
        if(f[i]==0){
            printf("Not in safe state\n");
            return 0;
        }
    }
    for(int i=0;i<5;i++){
        printf("P%d->",ans[i]);
    }
    return 1;
}
void requestResourse(int process,int request[],int f[], int ans[], int available[], int allocated_matrix[][4],int max_matrix[][4],int need[][4]){
    if(request[0]>need[process][0]&&
        request[1]>need[process][1]&&
        request[2]>need[process][2]&&
        request[3]>need[process][3]){
            printf("Request Denied\n");
            return;
        }
    for(int i=0;i<4;i++){
        if(request[i]>available[i]){
            printf("Request Denied");
            return;
        }
    }   
    for(int i=0;i<4;i++){
        available[i]-=request[i];
        allocated_matrix[process][i]+=allocated_matrix[process][i];
        need[process][i]=max_matrix[process][i]-allocated_matrix[process][i];
    }
    if(isSafe(f,ans,available,allocated_matrix,max_matrix,need)){
        printf("Grant request\n");
        return;
    }
    else{
        for(int i=0;i<4;i++){
            available[i]+=request[i];
            allocated_matrix[process][i]-=allocated_matrix[process][i];
            need[process][i]=max_matrix[process][i]-allocated_matrix[process][i];
        }
        printf("Not Granted");
    }
    return;
}
int main(){
    int f[5]={0,0,0,0,0};
    int ans[5];
    int available[4]={1, 0, 2, 1};
    int allocated_matrix[5][4]={{3,2,0,0},
                                {0,1,1,2},
                                {2,1,0,0},
                                {0,0,1,0},
                                {2,1,1,1}};
    int max_matrix[5][4]={  {3,2,1,1},
                            {0,1,3,3},
                            {2,1,1,0},
                            {1,1,2,1},
                            {3,2,1,2}};
    int need[5][4];
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            need[i][j]=max_matrix[i][j]-allocated_matrix[i][j]; 
        }
    }
    printf("%d",isSafe(f,ans,available,allocated_matrix,max_matrix,need));
    int request[4]={0,1,0,0};
    requestResourse(4,request,f,ans,available,allocated_matrix,max_matrix,need);
    for(int i=0;i<5;i++){
        printf("p%d->",ans[i]);
    }
}