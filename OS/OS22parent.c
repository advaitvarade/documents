#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

void selectionSort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i]<arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int main(){
    int n;
    printf("Enter the number of elemets\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elemets:");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    selectionSort(arr,n);

    char* argv[n+2];
    argv[0]="./OS22child";
    char s[n][20];
    for(int i=0;i<n;i++){
        sprintf(s[i],"%d",arr[i]);
        argv[i+1]=s[i];
    }
    argv[n+1]=NULL;

    int id=fork();
    if(id==-1){
        exit(1);
    } 
    else if(id==0){
        execve("./OS22child",argv,NULL);
        perror("excution failed");
        return 1;
    } 
    else{
        wait(NULL);
    }  
    return 0;
    
}
