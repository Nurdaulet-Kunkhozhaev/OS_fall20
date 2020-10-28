#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main() {
  char * filenameFrom = "./ex1.txt";
  char * filenameTo = "./ex1.memcpy.txt";

  int fdTo = open(filenameTo, O_RDWR);
  if (fdTo < 0)
    return 1;

  int fdFrom = open(filenameFrom, O_RDWR);
  if (fdFrom < 0)
    return 1;

  struct stat statbuf;
  int err = fstat(fdFrom, &statbuf);
  if (err < 0)
    return 1;
  int len = statbuf.st_size;

  ftruncate(fdTo, len);
  char * ptrFrom = mmap(NULL, len,
            PROT_READ|PROT_WRITE, MAP_SHARED,
            fdFrom, 0);
  if (ptrFrom == MAP_FAILED)
    return 1;

  char * ptrTo = mmap(NULL, len,
            PROT_READ|PROT_WRITE, MAP_SHARED,
            fdTo, 0);
  if (ptrTo == MAP_FAILED)
    return 1;

  close(fdTo);
  close(fdFrom);

  memcpy(ptrTo, ptrFrom, len);

  munmap(ptrFrom, len);
  munmap(ptrTo, len);
  return 0;
}
