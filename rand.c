#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int rand_n() {
  int fd;
  fd=open("/dev/random",O_RDONLY);
  int i;
  read(fd,&i,4);
  return i;
}

int main() {
  int ia[10];
  int i=0;
  printf("Generating random list\n");
  for (;i<10;i++) {
    ia[i]=rand_n();
  }
  i=0;
  for (;i<10;i++){
    printf("random %d: %d\n",i,ia[i]);
  }

  int fd;
  fd=open("foo",O_CREAT | O_WRONLY | O_EXCL ,0644);
  if (fd==-1) {
    printf("remember to remove foo! try again\n");
    return 0;
  }
  int bytes_written=write(fd,ia,sizeof(ia));
  printf("write returns: %d\n",bytes_written);
  printf("close returns: %d\n",close(fd));

  fd=open("foo",O_RDONLY);
  int check[10];
  int bytes_read=read(fd,check,sizeof(check));
  printf("read returns: %d\n",bytes_read,errno);

  
  if (bytes_read==-1)
    printf("error: %s\n",strerror(errno));
  
  i=0;
  for (;i<10;i++)
    printf("random %d: %d\n",i,check[i]);
  printf("close returns: %d\n",close(fd));
  return 0;

}
