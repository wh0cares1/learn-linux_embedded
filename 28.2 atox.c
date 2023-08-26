
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
#include <string.h>

int main(void)
{
    //long strtol(const char *nptr, char **endptr, int base);

    //long long strtoll(const char *nptr, char **endptr, int base);
    
    //strtoul strtoull u -> unsigned
    // printf("strtol : %ld\n",strtol("0x600",NULL,16));
    // printf("strtol : %ld\n",strtol("0x600",NULL,0));
    // printf("strtol : %ld\n",strtol("600",NULL,16));
    // printf("strtol : %ld\n",strtol("0777",NULL,8));
    // printf("strtol : %ld\n",strtol("0777",NULL,0));
    // printf("strtol : %ld\n",strtol("1111",NULL,2));
    // printf("strtol : %ld\n",strtol("-1110",NULL,2));

    //float number
    // printf("atof %lf\n",atof("0.123"));
    // printf("atof %lf\n",atof("-1.123"));
    // printf("atof %lf\n",atof("1000.123"));

    //strtof strtod strtold 
    // printf("strtof %f\n",strtof("0.123",NULL));
    // printf("strtod %lf\n",strtod("-1.123",NULL));
    // printf("strtold %Lf\n",strtold("1000.123",NULL));


    //how to convert number to string 
    char str[30] = {0};
    sprintf(str,"%d",500);
    puts(str);

    memset(str,0x0,sizeof(str));
    sprintf(str,"%f",500.111);
    puts(str);

    memset(str,0x0,sizeof(str));
    sprintf(str,"%u",500);
    puts(str);


    return 0;
}