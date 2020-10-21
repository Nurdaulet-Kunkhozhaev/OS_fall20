#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdbool.h>

#define MAX_FILES 1000

int main() {
  DIR *dirp = opendir("./tmp");

  struct dirent *dp;
  int file_count = 0;

  int *nodes = calloc(MAX_FILES, sizeof(int));
	char **names = calloc(MAX_FILES*MAX_FILES, 256);

  while ((dp = readdir(dirp)) != NULL){
	  nodes[file_count] = dp->d_ino;
    names[file_count] = dp->d_name;
    file_count++;
	}
  (void)closedir(dirp);

  bool *answer = calloc(file_count, sizeof(bool));
  int i, j, last_answer;
  for (i = 0; i < file_count; i++)
    answer[i] = false;

  for (i = 0; i < file_count; i++) {
    int cnt = 0, last_id = i, cur = nodes[i];

    for (j = 0; j < file_count; j++) {
      if (nodes[j] == cur) {
        cnt++;
        last_id = j;
        last_answer = j;
      }
    }

    if (cnt > 1) {
      answer[last_id] = true;
    }
  }

  for (i = last_answer; i >= 0; i--) {
    if (answer[i] == true) {
      for (j = i; j >= 0; j--) {
        if (nodes[j] == nodes[i])
        printf("%s ", names[j]);
      }
      printf("\n");
    }
  }
  return 0;
}
