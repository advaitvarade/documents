/*2.2 Implement the C program in which main program accepts an integer array. Main program uses the fork
system call to create a new process called a child process. Parent process sorts an integer array and passes
the sorted array to child process through the command line arguments of execve system call. The child
process uses execve system call to load new program that uses this sorted array for performing the binary
search to search the item in the array.*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/wait.h>
#define MAX_CHAIRS 3
pthread_t teacher_thread;
pthread_t students[8];


int student_count=0;

pthread_mutex_t mutex;
sem_t ta,students;

void * teacher(void * args){
    while(1){
        sem_wait(&students);
        pthread_mutex_lock(&mutex);
        student_count--;
        pthread_mutex_unlock(&mutex);   
        prinf("teacher meets student ");
        sleep(1);
        printf("student done next");
        sem_post(&ta);

    }
    pthread_exit(NULL);
}
void* student(void* args){
    while(1){
        sleep(rand()%5);
        pthread_mutex_lock(&mutex);
        if(student_count<MAX_CHAIRS){
            student_count++;
            sem_post(&student);
            printf("student in queue");
            pthread_mutex_unlock(&mutex);
            sem_wait(&ta);
        }
        else{
            pthread_mutex_unlock(&mutex);
            printf("queue full student come later");
        }
    }
}
