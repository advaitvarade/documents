#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
sem_t full,empty;
pthread_mutex_t lock;
int in=0, out=0;
void* producer(void* arg){
    int pizza_number = 0 ;
    while(1){
        pizza_number++;
        sleep(1);
        sem_wait(&empty);
        pthread_mutex_lock(&lock);
        buffer[in]=pizza_number;
        printf("produced pizza number:%d at counter number %d\n",pizza_number,in);
        in=(in+1)%BUFFER_SIZE;
        pthread_mutex_unlock(&lock);
        sem_post(&full);

    }
    pthread_exit(NULL);
}
void* consumer(void * arg){
    int pizza_ate;
    while(1){
        sleep(2);
        sem_wait(&full);
        pthread_mutex_lock(&lock);
        pizza_ate=buffer[out];
        printf("consumed pizza number:%d at counter number%d\n",pizza_ate,out);
        out=(out+1)%BUFFER_SIZE;
        pthread_mutex_unlock(&lock);
        sem_post(&empty);
    }
    pthread_exit(NULL);

}

int main(){
    pthread_t producer_thread,consumer_thread;
    pthread_mutex_init(&lock,NULL);
    sem_init(&empty, 0 , BUFFER_SIZE);
    sem_init(&full, 0 ,0);
    if(pthread_create(&producer_thread, NULL,producer,NULL)!=0){
        perror("failed");
    }
    if(pthread_create(&consumer_thread, NULL,consumer,NULL)!=0){
        perror("failed");
    }
    pthread_join(producer_thread,NULL);
    pthread_join(consumer_thread,NULL);
    pthread_mutex_destroy(&lock);
    sem_destroy(&empty);
    sem_destroy(&full);

}