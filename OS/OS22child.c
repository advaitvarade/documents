#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
void binarySearch(int arr[],int n,int key){
    int l=0,h=n-1;
    int mid;
    while(l<=h){
        int mid=(l+h)/2;
        if(arr[mid]==key){
            printf("found");
            return;
        }
        else if(arr[mid]<key){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }
    printf("Not found");
}
int main(int argc, char* argv[]){
    int arr[argc];
    for(int i=0;i<argc;i++){
        arr[i]=atoi(argv[i]);
    }
    printf("Enter the element to find");
    int key;
    scanf("%d",&key);
    binarySearch(arr,argc,key);

    return 0;    
}