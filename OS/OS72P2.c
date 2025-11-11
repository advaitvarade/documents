#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<stdlib.h>
#define SHM_SIZE 1024
int main(){
    key_t key=ftok("1234",65);
    int shm_id=shmget(key,SHM_SIZE,0);
    char * shm_ptr;
    shm_ptr=(char*) shmat(shm_id,NULL,0);
    printf("%s",shm_ptr);
    shmdt(shm_ptr);
    return 0;
}