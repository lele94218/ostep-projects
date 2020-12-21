#include "stat.h"
#include "types.h"
#include "user.h"

int main(int argc, char* argv[]) {
  int pid = fork();
  if (pid < 0) {
    printf(1, "fork failed...\n");
    exit();
  } else if (pid == 0) {
    // child goes here.
    printf(1, "child_1 %d\n", getpid());
    int i, j, a = 1, b = 2, tmp;
    for (i = 0; i < 10; ++i) {
      for (j = 0; j < 100; ++j) {
        tmp = a;
        a = b;
        b = tmp;
        printf(1, "%d %d\n", a, b);
      }
    }
    printf(1, "child_1 ticks: %d\n", getticks());
  } else {
    // parent continues.
    int next_pid = fork();
    if (next_pid < 0) {
      printf(1, "fork failed...\n");
      exit();
    } else if (next_pid == 0) {
      printf(1, "child_2 %d\n", getpid());
      int i, j, a = 1, b = 2, tmp;
      for (i = 0; i < 10; ++i) {
        for (j = 0; j < 100; ++j) {
          tmp = a;
          a = b;
          b = tmp;
          printf(1, "%d %d\n", a, b);
        }
      }
      printf(1, "child_2 ticks: %d\n", getticks());
    } else {
      wait();
    }
    wait();
  }
  exit();
}
