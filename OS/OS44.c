#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/wait.h>
#include<semaphore.h>

#define TOTAL_SEATS 50
int available_seats=50;
int reader_count=0;
pthread_mutex_t readers;
sem_t seats;

void* writer(void* args){
    sem_wait(&seats);
    available_seats=available_seats-1;
    printf("Booked seat number:%d\n",available_seats);
    sleep(1);
    sem_post(&seats);
    pthread_exit(NULL);
} 
void* reader(void* args){
    
    pthread_mutex_lock(&readers);
    reader_count++;
    sem_wait(&seats);
    pthread_mutex_unlock(&readers);

    printf("Seats Available:%d\n",available_seats);
    sleep(1);

    pthread_mutex_lock(&readers);
    reader_count--;
    if(reader_count==0){
        sem_post(&seats);
    }
    pthread_mutex_unlock(&readers);
    pthread_exit(NULL);
}
int main(){
    pthread_t thread[10];
    sem_init(&seats,0,1);
    pthread_mutex_init(&readers,NULL);
    while(1){
        int rand_number=rand() % 10;
        printf("%d\n",rand_number);
        sleep(5);
        if(rand_number%2==0){
            if(pthread_create(&thread[rand_number],NULL,writer,NULL)!=0){
                perror("Writer Thread not created");
                exit(1);
            }
        }
        else{
            if(pthread_create(&thread[rand_number],NULL,reader,NULL)!=0){
                perror("Reader Thread not created");
                exit(1);
            }
        }
    }
}