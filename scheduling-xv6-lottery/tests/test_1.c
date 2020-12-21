#include "stat.h"
#include "types.h"
#include "user.h"

void fork_children(int id) {
  if (id == 0)
    return;
  int pid = fork();
  if (pid < 0) {
    printf(1, "fork failed...\n");
    exit();
  } else if (pid == 0) {
    // child goes here.
    settickets(id);
    int i, j, a = 1, b = 2, tmp;
    for (i = 0; i < 10; ++i) {
      for (j = 0; j < 100; ++j) {
        tmp = a;
        a = b;
        b = tmp;
        printf(1, "%d %d\n", a, b);
      }
    }
    printf(1, "XV6_TEST_OUTPUT:%d\n", id);
  } else {
    // Parent goes here.
    fork_children((int)(id / 10));
    wait();
  }
}

int main(int argc, char* argv[]) {
  fork_children(100);
  wait();
  exit();
}
