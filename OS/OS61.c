#include<stdio.h>
#include<stdlib.h>
int isPageInFrames(int page,int frames[],int size){
    for(int i=0;i<size;i++){
        if(frames[i]==page)
            return i;
    }
    return -1;
}
int greatestInArray(int arr[],int size){
    int greatest=arr[0];
    int index=0;
    for(int i=1;i<size;i++){
        if(arr[i]>greatest){
            greatest=arr[i];
            index=i;
        }
    }
    return index;
}
int smallestInArray(int arr[],int size){
    int smallest=arr[0];
    int index=0;
    for(int i=1;i<size;i++){
        if(arr[i]<smallest){
            smallest=arr[i];
            index=i;
        }
    }
    return index;
}
void fifo(int ref_string[],int n,int s,int page){
    int frames[s];
    for(int i=0;i<s;i++)
        frames[i]=-1;
    int page_faults=0;
    int index=0;
    for(int i=0;i<n;i++){
        if(isPageInFrames(ref_string[i],frames,s)>=0){
            printf("Page %d page hit.\n",ref_string[i]);
        }
        else{
            frames[index%s]=ref_string[i];
            index++;
            page_faults++;
            printf("Page %d page fault.\n",ref_string[i]);
        }
    }
    printf("Total number of page faults: %d\n",page_faults);
}
int main(){
    int n,fsize;
    int page_faults=0;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int ref_string[n];
    for(int i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&ref_string[i]);
    }
    printf("Enter the number of frames in memory");
    scanf("%d",&fsize);

    //Fifo
    int frames[fsize];
    for(int i=0;i<fsize;i++)
        frames[i]=-1;
    fifo(ref_string,n,fsize,frames);
    //LRU page replacement algorithm
    int past[fsize];
    for(int i=0;i<fsize;i++){
        past[i]=-1;
    }
    for(int k=0;k<n;k++){
        if(isPageInFrames(ref_string[k],frames,fsize)>=0){
            printf("Page %d page Hit\n",ref_string[k]); 
        }
        else{
            int flag=0;
            for(int i=0;i<fsize;i++){
                past[i]=-1;
            }
            for(int i=0;i<fsize;i++){
                if(frames[i]==-1){
                    page_faults++;
                    flag=1;
                    printf("Page %d page fault\n",ref_string[k]);
                    frames[i]=ref_string[k];
                    break;
                }
            }
            if(flag==0){
                page_faults++;
                printf("Page %d page fault\n",ref_string[k]);
                for(int i=k-1;i>=0;i--){
                    int index=isPageInFrames(ref_string[i],frames,fsize);
                    if(index>=0){
                        past[index]=i;
                    }
                    else{
                        continue;
                    }
                }
                frames[smallestInArray(past,fsize)]=ref_string[k];
            }
        }
    }
    printf("LRU Page fautls:%d",page_faults);

    //optimal page replacement algorithm
    page_faults=0;
    int future[fsize];
    
    for(int i=0;i<fsize;i++)
        future[i]=99;
    
    for(int k=0;k<n;k++){
        for(int i=0;i<fsize;i++){
            printf("%d ",frames[i]);
        }printf("\t");
        if(isPageInFrames(ref_string[k],frames,fsize)>=0){
            printf("Page %d page Hit\n",ref_string[k]);
        }
        else{
             for(int i=0;i<fsize;i++)
                future[i]=99;
            int flag=0;
            for(int i=0;i<fsize;i++)
                if(frames[i]==-1){
                    page_faults++;
                    flag=1;
                    printf("Page %d page fault\n",ref_string[k]);
                    frames[i]=ref_string[k]; 
                    break;
                }
            if(flag==0){
                page_faults++;
                printf("Page %d page fault\n",ref_string[k]);
                for(int i=k+1;i<n;i++){
                    int index=isPageInFrames(ref_string[i],frames,fsize);
                    if(index==-1)continue;
                    future[index]=i;
                }
                frames[greatestInArray(future,fsize)]=ref_string[k];
            }    
        }
    }
    printf("Optimal Page fautls:%d",page_faults);
    return 0;
}