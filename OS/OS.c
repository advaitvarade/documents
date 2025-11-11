#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
void insertionSort(int arr[], int n){
    int key, j ;
    for(int i=0;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int reader_count=0;
sem_t seats;
pthread_mutex_t readers;
void * reader(void * args){
    pthread_mutex_lock(&readers);
    sem_wait(&seats);
    reader_count++;
    pthread_mutex_unlock(&readers);
    
    printf("");
    
    pthread_mutex_lock(&readers);
    reader_count--;
    if(reader_count==0){
        sem_post(&seats);
    }
    pthread_mutex_lock(&readers);
    pthread_exit(NULL);
}
void * writer(void *args){
    sem_wait(&seats);
    available--;
    sem_post(&seats);
}