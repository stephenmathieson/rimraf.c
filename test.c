
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include "path-join/path-join.h"
#include "rimraf.h"

static bool
exists(char *path) {
  struct stat b;
  return 0 == (stat(path, &b));
}

static void
test_setup() {
  char *dirs[] = {
    "./tmp",
    "./tmp/foo",
    "./tmp/foo/bar",
    "./tmp/foo/bar/baz",
    NULL
  };

  for (int i = 0; dirs[i]; i++) {
    mkdir(dirs[i], 0777);
    FILE *fp = fopen(path_join(dirs[i], "hello"), "w");
    fwrite("hello", 1, 5, fp);
    fclose(fp);
  }
}


int
main(void) {
  test_setup();
  assert(0 == rimraf("./tmp"));
  assert(false == exists("./tmp/foo/bar/baz/hello"));
  assert(false == exists("./tmp/foo/bar/hello"));
  assert(false == exists("./tmp/foo/hello"));
  assert(false == exists("./tmp/hello"));
  assert(false == exists("./tmp"));
  return 0;
}
