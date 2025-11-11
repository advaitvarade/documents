#include<stdio.h>
#include<stdlib.h>

void sort(int arr[], int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void LOOK(int ref[],int r_size, int header,int max){
    int sequence[r_size+1];
    sequence[0]=header;
    sort(ref,r_size);
    int k=1;
    for(int i=0;i<r_size;i++){
        if(ref[i]>=header){
            sequence[k++]=ref[i];
        }
    }
    for(int i=r_size-1;i>=0;i--){
        if(ref[i]<header){
            sequence[k++]=ref[i];
        }
    }
    int current=sequence[0];
    int total=0;
    for(int i=1;i<k;i++){
        total=total+abs(sequence[i]-current);
        current=sequence[i];
    }
    printf("total:%d",total);
    printf("avg time:%f",(float)total/r_size);
}
void CSCAN(int ref[], int n, int head, int max ){
    int seq[n+3];
    int k=1;
    seq[0]=head;
    sort(ref,n);
    for(int i=0;i<n;i++){
        if(ref[i]>=head){
            seq[k++]=ref[i];
        }
    }
    seq[k++]=max;
    seq[k++]=0;
    for(int i=0;i<n;i++){
        if(ref[i]<head){
            seq[k++]=ref[i];
        }
    }
    int total=0;
    int current=seq[0];
    for(int i=1;i<k;i++){
        printf("%d->",seq[i]);
        total=total+abs(seq[i]-current);
        current=seq[i];
    }
    printf("total:%d",total);
    printf("avg time:%f",(float)total/n);
}
void CLOOK(int ref[],int size, int head , int max){
    int seq[size+1];
    seq[0]=head;
    int k=1;
    sort(ref,size);
    for(int i=0;i<size;i++){
        if(ref[i]>=head){
            seq[k++]=ref[i];
        }
    }
    for(int i=0;i<size;i++){
        if(ref[i]<head){
            seq[k++]=ref[i];
        }
    }
    int total=0;
    int current=seq[0];
    for(int i=1;i<k;i++){
        printf("%d->",seq[i]);
        total=total+abs(seq[i]-current);
        current = seq[i];
    }
    printf("total:%d",total);
    printf("avg time:%f",(float)total/size);
}
void SCAN(int ref[], int size, int head, int max){
    int seq[size+1];
    seq[0]=head;
    int k=1;
    sort(ref,size);
    for(int i=0;i<size;i++){
        if(ref[i]>=head)
            seq[k++]=ref[i];
    }
    for(int i=size-1;i>=0;i--){
        if(ref[i]<head)
            seq[k++]=ref[i];
    }
    int total=0;
    int current = seq[0];
    for(int i=0;i<k;i++){
        printf("%d->",seq[i]);
        total=total + abs(seq[i] - current);
        current = seq[i];
    }
    printf("total:%d",total);
    printf("avg time:%f",(float)total/size);
}
int main(){
    int ref[]={10, 229, 39, 400, 18, 145, 120, 480, 20, 250};
    int r_size=10;
    int max=499;
    int head=85;
    SCAN(ref,r_size,head,max);
    
}