#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<ctype.h>
int main(){
    int fd=open("myfifo",O_RDONLY);
    char string[100];
    read(fd,&string,sizeof(string));
    for(int i=0;i<100;i++){
        string[i]=toupper(string[i]);
    }
    printf("%s",string);
}