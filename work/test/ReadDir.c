#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

char cwd[PATH_MAX];

int ReadDir() {
  if (getcwd(cwd, sizeof(cwd)) != NULL) {
    printf("Current working dir: %s\n", cwd);
  } else {
    perror("getcwd() error");
    return 1;
  }
  return 0;
}


