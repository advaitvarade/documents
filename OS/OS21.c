#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    int i, j ,key;
    for(i=0;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
int main(){
    int n;
    printf("Enter length of array\n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the arr elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int id=fork();
    if(id==0){
        printf("In child %d\n",getpid());
        insertionSort(arr,n);
        printf("sorting done child");
        sleep(5);
        sleep(5);
    }
    else{
        printf("In parent %d\n",getpid());
        bubbleSort(arr,n);
        printf("sorting done parent");
        
    }
     wait(NULL);
    return 0;
}
