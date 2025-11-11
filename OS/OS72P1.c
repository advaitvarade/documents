#include<stdio.h>
#include<sys/unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<stdlib.h>
#include<string.h>
#define SHM_SIZE 1024
int main(){
    int shm_id;
    char * shm_ptr;
    key_t key= ftok("1234",65);
    shm_id =shmget(key,SHM_SIZE,IPC_CREAT | 0666);
    shm_ptr = (char*) shmat(shm_id,NULL ,0 );
    if(shm_ptr ==(char * )-1){
        perror("shmat");
        exit(1);
    }
    char string[100];
    printf("Enter the value in the shared memory:\n");
    fgets(string,sizeof(string),stdin);
    strcpy(shm_ptr,string);
    sleep(10);
    shmdt(shm_ptr);
    return 0;
}