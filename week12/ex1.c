#include <stdio.h>

int main(void) {
  FILE *fp_read = fopen("/dev/random", "r");
  FILE *fp_write = fopen("ex1.txt", "w");

  char buf[255];
  fgets(buf, 21, fp_read);
  fputs(buf, fp_write);
  printf("%s\n", buf);

  fclose(fp_read);
  fclose(fp_write);
  return 0;
}
