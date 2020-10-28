#include <stdio.h>
#include <unistd.h>

int main() {
  char buff[1024];
  setvbuf(stdout, buff, _IOLBF, 1024);

  char output[] = "Hello";
  int i;
  for (i = 0; i < sizeof(output)/sizeof(char) - 1; i++) {
    printf("%c", output[i]);
    sleep(1);
  }
  return 0;
}
