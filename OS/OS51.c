#include<stdio.h>
#include<stdlib.h>

int main(){
    int f[5]={0,0,0,0,0};
    int ans[5];
    int available[4]={1, 0, 2, 1};
    int allocated_matrix[5][4]={{3,2,0,0},
                                {0,1,1,2},
                                {2,1,0,0},
                                {0,0,1,0},
                                {2,1,1,1}};
    int max_matrix[5][4]={  {5,3,1,1},
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
    int ind=0;
    for(int k=0;k<5;k++){
        for(int i=0;i<5;i++){
            if(f[i]==0){
                if( need[i][0]<=available[0] &&
                    need[i][1]<=available[1] &&
                    need[i][2]<=available[2] &&
                    need[i][3]<=available[3]){
                        ans[ind++]=i+1;
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
            printf("System is not in safe state:P%d",i);
            exit(0);
        }
    }    
    for(int i=0;i<5;i++){
        printf("P%d->",ans[i]);
    }                   
}