#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

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
  for (;i<10;i++) {
    ia[i]=rand_n();
    printf("random %d: %d\n",i,ia[i]);
  }

  int fd;
  fd=open("foo",O_CREAT | O_WRONLY | O_RDONLY,0644);
  int bytes_written=write("foo",ia,sizeof(ia));
  printf("write returns: %d",bytes_written);
  int check[10];
  read("foo",check,sizeof(check));
  i=0;
  for (;i<10;i++)
    printf("random %d: %d",i,check[i]);
  
  return 0;

}
