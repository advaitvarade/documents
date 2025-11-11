#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
    if(mkfifo("myfifo",0777)==-1){
        printf("could not create fifo");
        return 1;
    }
    int fd=open("myfifo",O_WRONLY);

    char string[100];
    printf("Enter a string");
    fgets(string,sizeof(string),stdin);
    printf("%s",string);
    write(fd,string,sizeof(string));

}