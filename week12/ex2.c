#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  bool overwrite = true;
  int skip_id = -1;

  int i;
  for (i = 0; i < argc; i++) {
    if (strcmp("-a", argv[i]) == 0) {
      overwrite = false;
      skip_id = i;
    }
  }

  char buf[1024];
  char *content = malloc(1024 * sizeof(char));

  int buf_size = 1024;
  while (fgets(buf, 1024, stdin)) {
    buf_size += 1024;
    char *old = content;
    content = realloc(content, buf_size);
    strcat(content, buf);
  }

  printf("%s", content);

  int files_number = argc - 1 - (1 - overwrite);

  FILE ** files = calloc(files_number, sizeof(FILE*));
  for (i = 1; i < argc; i++) {
    if (i == skip_id)
      continue;

    char * mode = overwrite ? "w" : "a";
    files[i - 1] = fopen(argv[i], mode);
    fprintf(files[i - 1], content);
    fclose(files[i - 1]);
  }
  return 0;
}
