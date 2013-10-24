
#include <stdio.h>
#include <string.h>
#include "src/rimraf.h"

/*
 * Run `rimraf` on the given paths
 *
 * Example:
 *
 *     $ rimraf a/b/c b/c/d /tmp/foo
 *
 */

int main(int argc, char **argv) {
  if (argc == 2) {
    if (0 == strcmp("--version", argv[1])
        || 0 == strcmp("-V", argv[1])) {
      printf("%s\n", RIMRAF_VERSION);
      return 0;
    }
  }

  for (int i = 1; i < argc; i++) {
    if (-1 == rimraf(argv[i])) {
      fprintf(stderr, "Failed to rimraf %s\n", argv[i]);
      return 1;
    }
  }

  return 0;
}
