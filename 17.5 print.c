#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{
    FILE *f = NULL;
    int ret;
    char buf[128]={0};
    f = fopen("./test.txt","w+");
    if(NULL == f)
    {
        perror("fopen error");
        return 1;
    }
    fprintf(f,"hi hello %d\n",100);
    fprintf(stdout,"hi hello %d\n",100);//stdin (0 fd) stdout (1 fd) stderr (2 fd)
    
    dprintf(1,"hi hello 1%d\n",100);// to stdout -> terminal
    dprintf(2,"hi hello 2%d\n",100);// to stderr -> terminal 

    sprintf(buf,"hi hello buf %d\n",200);// to the buf
    printf("%s\n",buf);//show buf

    snprintf(buf,128,"hi hello buf %d\n",300);// to the buf with size control
    printf("%s\n",buf);//show buf



    fclose(f);
    
    return 0;
}