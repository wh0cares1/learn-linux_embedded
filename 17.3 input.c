#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(void)
{

    char buf[128] = {0};
    //first time to ask you input
    scanf("%s",buf);
    printf("%s\n",buf);
    //second time ask you to input
    fscanf(stdin,"%s",buf);
    printf("%s\n",buf);

    //third
    int data;
    char buf1[128]={0};
    char buf2[128]={0};

    sscanf("100 hello world","%d %s %s",&data, buf1, buf2);
    printf("%d\n",data);
    printf("%s\n",buf1);
    printf("%s\n",buf2);

    return 0;


    return 0;
}