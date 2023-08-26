
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <utime.h>
#include <time.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void)
{
    //those are all outputs
    //puts("hello");
    //printf("hello");
    // putchar('A');
    // putchar('B');
    // putchar('C');
    // putchar('D');
    // putchar('E');
    // putchar(100);
    // putchar('\n');
    
    //stdin 0
    //stdout 1
    //stderr 2

    //int fd = open (xxxx);
    // fputc('A',stdout);
    // fputc('A',stdout);
    // fputc('A',stdout);
    // fputc('A',stdout);
    // fputc('\n',stdout);

    // fputs("hi mjj , how are you!\n",stdout);



    //those are all inputs
    //scanf();
    // char buf[256] = {0};
    // char buf1[256] = {0};
    // //gets(buf);
    // scanf("%s%s",buf,buf1);
    // puts(buf);
    // puts(buf1);

    // char s1[256] = {0};
    // char s2[256] = {0};
    // scanf("%s",s1);
    // printf("s1 -> %s\n",s1);
    

    // gets(s2);
    // printf("s2 -> %s\n",s2);
    // int ch;
    // ch = getchar();
    // printf("ch -> %c\n",ch);

    // char str[256]={0};
    // printf("input -> ");
    // //fgets(str,sizeof(str),stdin);
    // gets(str);
    // printf("%s",str);

    int ch = fgetc(stdin);
    printf("%c\n",ch);

    return 0;
}