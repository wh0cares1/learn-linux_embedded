#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
extern char **environ;//used very common
int main(int argc, char *argv[])
{
    int ret = -1;
    // if(3 > argc)
    // {
    //     return 1;
    // }
    //ret = putenv(argv[1]);//"TODAY=MONDAY"
    // ret = setenv(argv[1], argv[2], 0);
    // ret = setenv(argv[1], "SUNNNNN", 1);
    // if(ret)
    // {
    //     perror("putenv error");
    //     return 1;
    // }
    // putenv("AAA=100");
    // putenv("BBB=200");
    // putenv("CCC=300");
    // for(int i =0;NULL!=environ[i];i++)
    // {
    //     printf("%s\n",environ[i]);
    // }

    // unsetenv("AAA");
    // unsetenv("BBB");
    // environ=NULL;//used very common
    clearenv();
    if(NULL == environ)
    {
        return 1;
    }
    
    for(int i =0;NULL!=environ[i];i++)
    {
        printf("%s\n",environ[i]);
    }
    return 0;
}
    //    unsetenv(argv[1]);

    //environ = NULL; or clearenv();
    // clearenv();
    //ret = putenv(argv[1]);"TODAY=MONDAY"
    // ret = setenv(argv[1], "MONDAY", 0);
    // ret = setenv(argv[1], "TUESDAY", 1);
    // if(ret)
    // {
    //     perror("setenv error");
    //     return 1;
    // }