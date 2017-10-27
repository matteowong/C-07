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

  return 0;

}
