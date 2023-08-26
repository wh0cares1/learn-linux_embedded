#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{

    struct stat st;
    int ret;
    /*int fd;
    fd = open("./test.txt",O_RDWR);
    if(-1==fd)
    {
        perror("open error");
        return 1;
    }

    ret = fstat(fd,&st);*/
    //ret = lstat("./test.txt",&st); //stat()
    ret = lstat("./linkfile",&st);
    if(-1==ret)
    {
        perror("stat error");
        return 1;
    }

    printf("File type:                ");

   switch (st.st_mode & S_IFMT) {
    case S_IFBLK:  printf("block device\n");            break;
    case S_IFCHR:  printf("character device\n");        break;
    case S_IFDIR:  printf("directory\n");               break;
    case S_IFIFO:  printf("FIFO/pipe\n");               break;
    case S_IFLNK:  printf("symlink\n");                 break;
    case S_IFREG:  printf("regular file\n");            break;
    case S_IFSOCK: printf("socket\n");                  break;
    default:       printf("unknown?\n");                break;
    }

    printf("I-node number:            %ld\n", (long) st.st_ino);
    printf("Mode:                     %lo (octal)\n",(unsigned long) st.st_mode);
    printf("Link count:               %ld\n", (long) st.st_nlink);
    printf("Ownership:                UID=%ld   GID=%ld\n",(long) st.st_uid, (long) st.st_gid);
    printf("Preferred I/O block size: %ld bytes\n",(long) st.st_blksize);
    printf("File size:                %lld bytes\n",(long long) st.st_size);
    printf("Blocks allocated:         %lld\n",(long long) st.st_blocks);
    printf("Last status change:       %s", ctime(&st.st_ctime));
    printf("Last file access:         %s", ctime(&st.st_atime));
    printf("Last file modification:   %s", ctime(&st.st_mtime));

    exit(EXIT_SUCCESS);

}