
//
// rimraf.c
//
// Copyright (c) 2013 Stephen Mathieson
// MIT licensed
//

#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include "rimraf.h"
#include "path-join.h"

/*
 * rm -rf $path
 */

int rimraf(char *path) {
  DIR *dir = opendir(path);
  if (NULL == dir) return -1;

  struct dirent *dp = NULL;
  while (NULL != (dp = readdir(dir))) {
    if (0 == strcmp(".", dp->d_name)
        || 0 == strcmp("..", dp->d_name)) continue;

    char *f = path_join(path, dp->d_name);
    if (NULL == f) return -1;

    struct stat s;
    if (0 != stat(f, &s)) return -1;
    if (s.st_mode & S_IFDIR) {
      // rimraf dirs
      if (-1 == rimraf(f)) return -1;
    } else {
      // unlink files
      if (-1 == unlink(f)) return -1;
    }
    free(f);
  }
  free(dp);
  closedir(dir);

  return rmdir(path);
}
