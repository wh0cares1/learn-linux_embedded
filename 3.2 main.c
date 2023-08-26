#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) 
{
	 char buff[1024];
	 int fd1, fd2;
	 int ret;
	 /*open src_file with readonly*/
	 fd1 = open("./src_file", O_RDONLY);
	 if (-1 == fd1)
 		return fd1;
	 /*open another dest_file writeonly*/
	 fd2 = open("./dest_file", O_WRONLY);
	 if (-1 == fd2) {
		 ret = fd2;
		 goto out1;
	 }
 	/* read 1KB data to buff from src_file*/
 	ret = read(fd1, buff, sizeof(buff));
 	if (-1 == ret)
 		goto out2;
 	/* write buff to dest_file*/
 	ret = write(fd2, buff, sizeof(buff));
 	if (-1 == ret)
 		goto out2;
 	ret = 0;
	
	out2:
 	/* close  dest_file*/
  		close(fd2);
	out1:
 	/* close src_file*/
 		close(fd1);
 	return ret; 
 }
