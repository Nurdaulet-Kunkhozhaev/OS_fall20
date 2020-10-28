#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main() {
  char * filename = "./ex1.txt";
  char * newString = "This is a nice day\n";
  int len = 19;

  int fd = open(filename, O_RDWR);
  if (fd < 0)
    return 1;

  ftruncate(fd, len);
  char * ptr = mmap(NULL, len,
            PROT_READ|PROT_WRITE, MAP_SHARED,
            fd, 0);
  if (ptr == MAP_FAILED)
    return 1;

  close(fd);

  memcpy(ptr, newString, len);

  int err = munmap(ptr, len);
  if (err != 0)
    return 1;
  return 0;
}
